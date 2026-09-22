param(
    [Parameter(Mandatory = $true, Position = 0, ValueFromRemainingArguments = $true)]
    [string[]]$Path,

    [int]$MaxLength = 35
)

$ErrorActionPreference = 'Stop'
$issues = [System.Collections.Generic.List[object]]::new()
$englishPattern = '\b(the|you|your|this|that|with|from|have|trainer|battle|league|could|would|should|where|when|what|will|been|were)\b'

$files = foreach ($entry in $Path) {
    if (Test-Path -LiteralPath $entry -PathType Leaf) {
        Get-Item -LiteralPath $entry
    } elseif (Test-Path -LiteralPath $entry -PathType Container) {
        Get-ChildItem -LiteralPath $entry -Recurse -Filter 'scripts.inc' -File
    } else {
        throw "No existe la ruta: $entry"
    }
}

foreach ($file in $files | Sort-Object FullName -Unique) {
    $lineNumber = 0
    $newlinesInParagraph = 0

    foreach ($line in Get-Content -LiteralPath $file.FullName -Encoding UTF8) {
        $lineNumber++
        if ($line -notmatch '\.string\s+"(.*)"') {
            continue
        }

        $text = $Matches[1]
        foreach ($segment in [regex]::Split($text, '\\[nlp]|\$')) {
            if ($segment.Length -gt $MaxLength) {
                $issues.Add([pscustomobject]@{
                    Tipo = 'LONGITUD'
                    Archivo = $file.FullName
                    Linea = $lineNumber
                    Detalle = "$($segment.Length) caracteres: $segment"
                })
            }
        }

        if ($text -match $englishPattern) {
            $issues.Add([pscustomobject]@{
                Tipo = 'INGLES?'
                Archivo = $file.FullName
                Linea = $lineNumber
                Detalle = $text
            })
        }

        foreach ($token in [regex]::Matches($text, '\\[nlp]|\$')) {
            switch ($token.Value) {
                '\n' {
                    $newlinesInParagraph++
                    if ($newlinesInParagraph -gt 1) {
                        $issues.Add([pscustomobject]@{
                            Tipo = 'SALTO'
                            Archivo = $file.FullName
                            Linea = $lineNumber
                            Detalle = 'Más de un \n antes de \p o $'
                        })
                    }
                }
                '\p' { $newlinesInParagraph = 0 }
                '$'  { $newlinesInParagraph = 0 }
            }
        }
    }
}

if ($issues.Count -eq 0) {
    Write-Host "OK: $($files.Count) archivo(s) sin incidencias detectadas."
    exit 0
}

$issues | Sort-Object Archivo, Linea, Tipo | Format-Table -AutoSize -Wrap
Write-Host "Incidencias: $($issues.Count)"
exit 1

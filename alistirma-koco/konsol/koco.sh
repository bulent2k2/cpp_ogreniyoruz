#!/bin/bash
# Kullanım: koco.sh betik.kojo [girdi-dosyası]
# Betiği Koco'nun konsol alt kümesiyle derleyip çalıştırır: çıktı penceresine
# yazılanlar standart çıktıya gider; kaplumbağa komutları çizmez, yalnız
# konum/yön tutar (stderr'e özet). Önce kur.sh çalıştırılmış olmalı.
set -e
export LC_ALL=C.UTF-8 LANG=C.UTF-8
K="$(cd "$(dirname "$0")" && pwd)"; L="$K/kojo/scala-tr/build/pack/lib"
B="$1"; G="${2:-/dev/null}"
D=$(mktemp -d "${TMPDIR:-/tmp}/koco.XXXX")
{ echo 'import net.kogics.kojo.lite.i18n.KonsolAPI._'; echo 'object Betik {'; cat "$B"; echo; echo 'def main(args: Array[String]): Unit = ()'; echo '}'; } > "$D/Betik.scala"
java -Dsun.jnu.encoding=UTF-8 -Dfile.encoding=UTF-8 -cp "$L/*:$K/out" scala.tools.nsc.Main -usejavacp -cp "$K/out" -d "$D" "$D/Betik.scala" 2>&1 | grep -v "JAVA_TOOL\|^\[Kojo\]" >&2 || true
if [ ! -f "$D/Betik.class" ]; then echo "DERLENMEDİ"; rm -rf "$D"; exit 1; fi
java -Dsun.jnu.encoding=UTF-8 -Dfile.encoding=UTF-8 -Dstdout.encoding=UTF-8 -Dstderr.encoding=UTF-8 -Xss64m -cp "$D:$K/out:$L/scala-library.jar" Betik < "$G" 2> >(grep -v JAVA_TOOL >&2)
rc=$?; rm -rf "$D"; exit $rc

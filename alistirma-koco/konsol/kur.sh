#!/bin/bash
# Konsol düzeneğini kurar: Koco'nun Türkçe anahtar sözcüklü Scala derleyicisini
# (bulent2k2/kojo deposundaki scala-tr jar'ları) ve Türkçe API'nin standart
# kütüphaneyle çalışan parçalarını alıp konsol alt kümesini derler.
# Gerekenler: git, Java 17+, Python 3. Bir kere çalıştırmak yeter.
set -e
export LC_ALL=C.UTF-8 LANG=C.UTF-8
K="$(cd "$(dirname "$0")" && pwd)"
KOJO_SURUM=965de1e7784e4b6b2c427d79f45ea026c5c6676d   # sınanmış kojo sürümü; yenilerken README'yi de güncelleyin
if [ ! -d "$K/kojo/.git" ]; then
  git clone --depth 1 --filter=blob:none --no-checkout https://github.com/bulent2k2/kojo "$K/kojo"
  git -C "$K/kojo" sparse-checkout init --cone
  git -C "$K/kojo" sparse-checkout set scala-tr/build/pack/lib src/main/scala/net/kogics/kojo/lite/i18n/tr
fi
git -C "$K/kojo" fetch --depth 1 --filter=blob:none origin "$KOJO_SURUM"
git -C "$K/kojo" checkout --detach "$KOJO_SURUM"
rm -rf "$K/src" "$K/out"; mkdir -p "$K/src" "$K/out"
python3 "$K/yama.py" "$K/kojo" "$K/src"
cp "$K/package.scala" "$K/KonsolAPI.scala" "$K/Kaplumbaga.scala" "$K/src/"
L="$K/kojo/scala-tr/build/pack/lib"
java -Dsun.jnu.encoding=UTF-8 -Dfile.encoding=UTF-8 -cp "$L/*" scala.tools.nsc.Main -usejavacp -d "$K/out" "$K"/src/*.scala
echo "kuruldu: $K/out  (sınamak için: make -C ../kod test)"

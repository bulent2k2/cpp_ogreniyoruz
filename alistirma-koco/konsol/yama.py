#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Kojo deposundaki Türkçe API dosyalarından yalnız standart kütüphaneyle
derlenebilenleri alır, Kojo çekirdeğine bağımlı parçalarını atar.
Kullanım: python3 yama.py <kojo-deposu> <hedef-dizin>  (kur.sh çağırır)"""
import pathlib, re, shutil, sys

kojo = pathlib.Path(sys.argv[1]); hedef = pathlib.Path(sys.argv[2]); hedef.mkdir(parents=True, exist_ok=True)
tr = kojo / "src/main/scala/net/kogics/kojo/lite/i18n/tr"
for f in ("sayi harf aralik belki kokturler kume eslem dizi dizik dizim yoney kuyruk "
          "ikisindenbiri miskindizin yazi yineleyici bolumselislev buan").split():
    shutil.copy(tr / f"{f}.scala", hedef / f"{f}.scala")

s = (tr / "dizin.scala").read_text(encoding="utf-8")
s = s.replace("import scala.collection.parallel.CollectionConverters._\nimport scala.collection.parallel\n", "")
s = re.sub(r"trait ParalelDiziYöntemleri \{.*?\n\}\n", "", s, flags=re.S)
s = re.sub(r"\n *type ParDizi\[T\] = parallel.*?\n", "\n", s)
s = re.sub(r"\n *def paralel: ParDizi\[T\] = d\.par\n", "\n", s)
(hedef / "dizin.scala").write_text(s, encoding="utf-8")

m = (tr / "matematik.scala").read_text(encoding="utf-8")
m = re.sub(r"import org\.apache.*?\n", "", m)
m = re.sub(r"import net\.kogics.*?\n", "", m)
for _ in range(2):
    m = re.sub(r"\n *def enUfakOrtakKat.*?\n", "\n", m)
    m = re.sub(r"\n *def enİriOrtakPayda.*?\n", "\n", m)
m = re.sub(r"\n *def uzaklık\(n1: Nokta.*?\n", "\n", m)
m = re.sub(r"\n *def açı\(n1: Nokta.*?\n", "\n", m)
m = "\n".join(l for l in m.split("\n") if "StatUtils" not in l and "ArithmeticUtils" not in l)
(hedef / "matematik.scala").write_text(m, encoding="utf-8")
print(f"{hedef}: {len(list(hedef.glob('*.scala')))} dosya")

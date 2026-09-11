/* ===========================================================
   "Hepsini seç" düğmesi.

   Her kod bloğunun sağ üst köşesine bir düğme koyar; tıklayınca
   bloğun tamamını seçer ve panoya kopyalar. Amaç bir örneği iKojo'ya
   (ya da çevrimiçi bir derleyiciye) yapıştırmayı kolaylaştırmak.

   Üç karar ve nedenleri:

   1. Düğme HTML'e yazılmıyor, bu betik ekliyor. Böylece betiğin
      çalışmadığı yerlerde -- e-mürekkep okuyucular, baskı -- ölü bir
      düğme görünmüyor. Baskıda ayrıca biçem dosyası da gizliyor.

   2. Önce seçiyor, sonra kopyalamayı deniyor. Kum havuzundaki
      çerçevelerde ve bazı e-kitap okuyucularında pano izni yok; seçim
      ise her yerde çalışıyor. Kopyalama tutmazsa öğrenci Ctrl+C'ye
      basıp devam edebilir, düğme de bunu yazıyor.

   3. Ekranda görünen yazılar \u kaçışlarıyla yazıldı: EPUB okuyucusu bu
      dosyanın kodlamasını yanlış varsaysa bile düğmenin üstündeki Türkçe
      doğru çıksın diye. Yorumlarda böyle bir kaygı yok; onlar Türkçe
      duruyor, çünkü kimse onları ekranda görmüyor ve yanlış çözülmüş bir
      yorum da programı bozmuyor.
   =========================================================== */

(function () {
  "use strict";

  var SEC = "Hepsini seç";                     // Hepsini seç
  var TAMAM = "Kopyalandı";                    // Kopyalandı
  var SECILDI = "Seçildi — Ctrl+C";       // Seçildi — Ctrl+C
  var CIKTI = "çıktı";               // çıktı
  var YARDIM = "Kod bloğunun tamamını seç ve kopyala";
  var SURE = 1800;                                  // geri bildirim, milisaniye

  /* Düğmenin yazısını geçici olarak değiştirir, sonra eski hâline döner. */
  function bildir(dugme, yazi, basarili) {
    dugme.textContent = yazi;
    if (basarili) {
      dugme.setAttribute("data-durum", "tamam");
    } else {
      dugme.removeAttribute("data-durum");
    }
    if (dugme.zamanlayici) {
      clearTimeout(dugme.zamanlayici);
    }
    dugme.zamanlayici = setTimeout(function () {
      dugme.textContent = SEC;
      dugme.removeAttribute("data-durum");
    }, SURE);
  }

  /* Kod bloğunun tamamını seçer. Kopyalama için de gereken adım bu. */
  function sec(kod) {
    try {
      var secim = window.getSelection();
      if (!secim) {
        return false;
      }
      var aralik = document.createRange();
      aralik.selectNodeContents(kod);
      secim.removeAllRanges();
      secim.addRange(aralik);
      return true;
    } catch (e) {
      return false;
    }
  }

  function tikla(kod, dugme) {
    var secildi = sec(kod);
    var kopyalandi = false;
    // execCommand eskimiş sayılıyor ama kum havuzundaki çerçevelerde hâlâ
    // en çok çalışan yol; seçimi kopyaladığı için ayrı bir alan gerekmiyor.
    try {
      kopyalandi = !!(document.execCommand && document.execCommand("copy"));
    } catch (e) {
      kopyalandi = false;
    }
    if (kopyalandi) {
      bildir(dugme, TAMAM, true);
      return;
    }
    // Olmadıysa yeni pano arayüzünü dene; bu eşzamansız çalışıyor.
    var pano = navigator.clipboard;
    if (pano && pano.writeText) {
      pano.writeText(kod.textContent).then(
        function () { bildir(dugme, TAMAM, true); },
        function () { bildir(dugme, secildi ? SECILDI : SEC, false); }
      );
      return;
    }
    bildir(dugme, secildi ? SECILDI : SEC, false);
  }

  function kur() {
    var bloklar = document.querySelectorAll("figure.kod");
    for (var i = 0; i < bloklar.length; i++) {
      var blok = bloklar[i];
      var basi = blok.querySelector("figcaption");
      var kod = blok.querySelector("pre code") || blok.querySelector("pre");
      if (!basi || !kod || basi.querySelector(".kopyala")) {
        continue;
      }
      // Çıktı blokları yapıştırılacak bir betik değil; onlara düğme koymuyoruz.
      var ad = basi.querySelector(".ad");
      if (ad && ad.textContent.replace(/\s+/g, "") === CIKTI) {
        continue;
      }
      var dugme = document.createElement("button");
      dugme.setAttribute("type", "button");
      dugme.className = "kopyala";
      dugme.textContent = SEC;
      dugme.setAttribute("aria-label", YARDIM);
      basi.appendChild(dugme);
      dugme.addEventListener("click", (function (k, d) {
        return function () { tikla(k, d); };
      })(kod, dugme));
    }
  }

  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", kur);
  } else {
    kur();
  }
})();

/* ===========================================================
   "Hepsini seç" düğmesi.

   Her kod bloğunun sağ üst köşesine bir düğme koyar; tıklayınca
   bloğun tamamını seçer ve panoya kopyalar. Amaç bir örneği iKojo'ya
   (ya da çevrimiçi bir derleyiciye) yapıştırmayı kolaylaştırmak.

   Dört karar ve nedenleri:

   1. Düğme HTML'e yazılmıyor, bu betik ekliyor. Böylece betiğin
      çalışmadığı yerlerde -- e-mürekkep okuyucular, baskı -- ölü bir
      düğme görünmüyor. Baskıda ayrıca biçem dosyası da gizliyor.

   2. Önce seçiyor, sonra kopyalamayı deniyor. Kum havuzundaki
      çerçevelerde ve bazı e-kitap okuyucularında pano izni yok; seçim
      ise her yerde çalışıyor. Kopyalama tutmazsa öğrenci Ctrl+C'ye
      basıp devam edebilir, düğme de bunu yazıyor. Seçim de tutmadıysa
      kopyalamayı hiç denemiyoruz: yoksa öğrencinin sayfada daha önce
      seçtiği başka bir metni panoya atardık.

   3. Yapıştırılacak bir betik olmayan bloklar -- program çıktısı,
      uçbirim dökümü, derleyici hatası, tümevarım formülü -- düğme
      almıyor. Bunları başlıktaki addan tahmin etmiyoruz; blok
      <figure class="kod kopyalanmaz"> diye işaretleniyor. Ada bakmak
      kırılgandı: adlar (çıktı, terminal, izleme, çalışırken, tümevarım,
      derleyici ...) iki kitapçıkta çeşitleniyor ve yeni bir ad eklenince
      liste sessizce eskiyordu.

   4. Ekranda görünen yazılar \u kaçışlarıyla yazıldı: EPUB okuyucusu bu
      dosyanın kodlamasını yanlış varsaysa bile düğmenin üstündeki Türkçe
      doğru çıksın diye. Yorumlarda böyle bir kaygı yok; onlar Türkçe
      duruyor, çünkü kimse onları ekranda görmüyor ve yanlış çözülmüş bir
      yorum da programı bozmuyor.
   =========================================================== */

(function () {
  "use strict";

  var SEC = "Hepsini seç";                              // Hepsini seç
  var TAMAM = "Kopyalandı";                             // Kopyalandı
  var SECILDI = "Seçildi — Ctrl+C";                // Seçildi — Ctrl+C
  var YARDIM = "Kod bloğunun tamamını " +     // Kod bloğunun tamamını
               "seç ve kopyala";                        // seç ve kopyala
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
    // Seçemediysek çağırmıyoruz: seçimi kopyalar, bizimki de seçim değil.
    try {
      kopyalandi = !!(secildi && document.execCommand &&
                      document.execCommand("copy"));
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
    // Yapıştırılacak betik olmayan bloklar "kopyalanmaz" diye işaretli.
    var bloklar = document.querySelectorAll("figure.kod:not(.kopyalanmaz)");
    for (var i = 0; i < bloklar.length; i++) {
      var blok = bloklar[i];
      var basi = blok.querySelector("figcaption");
      var kod = blok.querySelector("pre code") || blok.querySelector("pre");
      if (!basi || !kod || basi.querySelector(".kopyala")) {
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

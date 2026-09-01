// Koco kitapçığını PDF'e çevirir.  Kullanım: node kitapcik-koco/pdf.mjs
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { createRequire } from 'node:module';

// Playwright'ı önce yerel kurulumdan (npm install playwright), olmazsa
// bilinen konumlardan yükle. Kurulum için README'deki "Gerekli araçlar"
// bölümüne bakın.
const require = createRequire(import.meta.url);
function playwrightYükle() {
  const adaylar = [
    'playwright',                                // depo kökünde: npm install playwright
    'playwright-core',
    '/opt/node22/lib/node_modules/playwright',   // bulut çalışma ortamı
  ];
  for (const aday of adaylar) {
    try { return require(aday); } catch { /* sıradakini dene */ }
  }
  console.error("Playwright bulunamadı. Depo kökünde şunları çalıştırın:\n" +
    "    npm install playwright\n    npx playwright install chromium");
  process.exit(1);
}
const { chromium } = playwrightYükle();

const kok = path.dirname(fileURLToPath(import.meta.url));
const girdi = path.join(kok, 'cikti', 'kitapcik-tam.html');
const cikti = process.argv[2] ||
  path.join(kok, '..', 'kitap', 'Programlamaya-ve-Algoritmalara-Keyifli-ve-Islevsel-Bir-Giris.pdf');

const b = await chromium.launch();
const p = await b.newPage({ colorScheme: 'light' });
await p.goto('file://' + girdi, { waitUntil: 'networkidle' });
await p.emulateMedia({ media: 'print' });
await p.waitForTimeout(2500);          // yazı tipleri yerleşsin

const kucuk = `font-family:-apple-system,system-ui,sans-serif;font-size:7.5pt;
  color:#8792AA;width:100%;padding:0 14mm;`;

await p.pdf({
  path: cikti,
  format: 'A4',
  printBackground: true,
  displayHeaderFooter: true,
  headerTemplate: `<div style="${kucuk}"></div>`,
  footerTemplate: `<div style="${kucuk}display:flex;justify-content:space-between;">
      <span>Programlamaya ve Algoritmalara Keyifli ve İşlevsel Bir Giriş</span>
      <span class="pageNumber"></span>
    </div>`,
  margin: { top: '14mm', bottom: '16mm', left: '16mm', right: '14mm' },
});
await b.close();
console.log('PDF yazıldı: ' + cikti);

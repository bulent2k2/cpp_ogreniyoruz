// Kapak resmini üretir: kapak-tasarim.html -> kitap/kapak.png (1600x2400)
// Kullanım: node kitapcik/kapak.mjs
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
const b = await chromium.launch();
const p = await b.newPage({ viewport: { width: 1600, height: 2400 } });
await p.goto('file://' + path.join(kok, 'kapak-tasarim.html'), { waitUntil: 'networkidle' });
await p.waitForTimeout(2000);          // yazı tipleri yerleşsin
await p.screenshot({ path: path.join(kok, '..', 'kitap', 'kapak.png') });
await b.close();
console.log('kitap/kapak.png yazıldı');

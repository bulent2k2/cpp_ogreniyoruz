// Koco kitapçığını PDF'e çevirir.  Kullanım: node kitapcik-koco/pdf.mjs
import { chromium } from '/opt/node22/lib/node_modules/playwright/index.mjs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

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

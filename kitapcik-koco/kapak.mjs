// Koco kitapçığının kapak resmini üretir: kapak-tasarim.html -> kitap/kapak-koco.png (1600x2400)
// Kullanım: node kitapcik-koco/kapak.mjs
import { chromium } from '/opt/node22/lib/node_modules/playwright/index.mjs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const kok = path.dirname(fileURLToPath(import.meta.url));
const b = await chromium.launch();
const p = await b.newPage({ viewport: { width: 1600, height: 2400 } });
await p.goto('file://' + path.join(kok, 'kapak-tasarim.html'), { waitUntil: 'networkidle' });
await p.waitForTimeout(2000);          // yazı tipleri yerleşsin
await p.screenshot({ path: path.join(kok, '..', 'kitap', 'kapak-koco.png') });
await b.close();
console.log('kitap/kapak-koco.png yazıldı');

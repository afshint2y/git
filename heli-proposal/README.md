# Heli Studio Proposal — Pocky

Interactive project proposal for **Pocky Group AB** (Visual Identity & Packaging Design, reference HS-2026-042, issued 21 October 2026). A single static page: no build step, no framework, no dependencies.

## Run it

Open `index.html` in a browser, or serve the folder (recommended, so the video and fonts load the same way they will in production):

```sh
cd heli-proposal
python3 -m http.server 8000
# open http://localhost:8000
```

Deploy by uploading the folder as-is to any static host (Netlify, Vercel, GitHub Pages, S3, the studio's own server). All paths are relative.

## Files

```
index.html            the whole page: CSS, content and JavaScript
fonts/                Inter Variable (woff2, latin), self-hosted, taken from heli.studio
assets/               cover film and poster, approach images, contact cards, AI section photo
assets/work/          case study images (Heli Technology, Money Mend, Dizno), AVIF
```

No external requests except the `mailto:` links and the outbound links to heli.studio, Behance, Dribbble and LinkedIn.

## How index.html is organised

1. **CSS** in one `<style>` block, built in layers. Later blocks override earlier ones, so edit or add at the end of a layer rather than the top. The last layers are, in order:
   - `/* Pocky instance … */` — layouts specific to this proposal (understanding columns, approach tags, team line, how-we-start, ticket stub, cover grid)
   - `/* touch screens have no hover … */` — `@media (hover:none)` cues for phones and tablets
   - `/* ── phone layout fixes ── */` — `@media (max-width:760px)` overrides
   - `/* ════ heli.studio typography ════ */` — the type system taken from heli.studio: Inter Variable, 140% line height, weights 400/500, −4% heading tracking, 12px medium uppercase labels, fluid sizes
2. **Content**: the `PROPOSAL` object near the top of the `<script>` block. All client text, prices, weeks, team, terms and contact details live here. To make a proposal for another client, edit this object only.
3. **Rendering**: one function per section (`M.cover`, `M.challenge`, …). `ORDER` sets the section order. Values that depend on the selected services (total, weeks, sessions, payment amounts, CTA text) are filled through `data-bind="…"` attributes in `bind()`.
4. **Interactions**, each in its own block below the renderers: service selection and pricing, scope/process tabs, timeline (pinned and scroll-driven on desktop, swipeable on phones), case study drawer, the two dialogs (Start the journey / Request changes, both open a prefilled email), section navigation, the flipping price ticket, the tear-off total stub, and the draggable cards.

## Content model (`PROPOSAL`)

| Key | What it drives |
| --- | --- |
| `client`, `project` | Cover, footers, ticket serials, email subjects. `project.version` is the reference number. |
| `currency` | Prefix for every amount (`$`). |
| `services[]` | Investment tickets, scope tabs, process tabs, timeline rows. `price`, `weeks`, `ticket` (ticket bullet list), `activities` and `deliverables` (scope), `spec` (scope specifics). `after: {id, week}` starts this service at that week when the other service is also selected. |
| `bundle` | Package credit applied when all `bundle.ids` are selected (`credit`, `note`, `sequence`). |
| `process.<serviceId>[]` | Phases: `start`/`end` are weeks inside the service (0-based), `glyph` picks the animated icon. |
| `timeline.<serviceId>` | Bars `[label, start, end, row]` and sessions `[label, weekPosition]`. |
| `payment.split` | Milestones as `[label, fraction]`; amounts are computed from the selected total. |
| `team.roles` | `[initials, role, phase, description]`; the phase is not shown at the moment. |
| `work.cases[]` | Case cards and drawer: `name`, `tags`, `outcome`, `imgs` (first image is the card cover). |
| `terms`, `steps`, `start`, `contact`, `capabilities` | Terms grid, How we start, Earliest start, Contact, Other services. |

Current numbers: Visual Identity $5,000 (6 weeks) + Packaging Design $3,000 (5 weeks, starts after week 5) − $2,000 package credit = **$6,000, 10 weeks, 7 sessions**. Paid 40/30/30 ($2,400 · $1,800 · $1,800).

## Checked

- Desktop 1440×900, and phones/tablets at 360, 390, 414 and 768px wide: no horizontal overflow, no console errors.
- Touch: ticket flips on tap, stub tears on tap or pull, process phases open on tap, cards swipe.
- `prefers-reduced-motion` turns the animations off.

## Notes for the developer

- The approach image `approach-house.webp` carries a © René Heylen / 1x.com watermark in its bottom corner (cropped out in the strip). Confirm the licence or replace it before the page goes public.
- `assets/heli-ai.jpg` has a black notch above the head from its source; the first question bubble is positioned over it on purpose, on desktop and on phones. Keep that bubble in place or replace the photo.
- The case study drawer shows images, services and the outcome only; there is no long-form case text yet.
- The CSS has grown in layers with many `!important` overrides. If this becomes a reusable template, consolidating the layers is the first thing worth doing.

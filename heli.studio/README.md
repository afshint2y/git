# heli.studio static snapshot

Static copy of the site from `heli.studio_1.zip`, repaired so it loads without errors.

## Run

```sh
python3 -m http.server 9000 --directory heli.studio
# open http://localhost:9000/
```

## What was fixed

- Removed the stray `<?xml encoding="utf-8" ?>` line the scraper put before `<html>`.
- Removed ~25 `modulepreload` links and the loader-video preload; their files were not in the zip (all 404).
- Removed the full-screen loading overlay, which was stuck at "0%/50%" forever because the app script that hides it never loads.
- Removed the app entry script (`js/index-*.js`). It statically imports 13 chunks that aren't in the zip, so it could never run. Removed the router hydration data along with it.
- Added `js/static-nav.js` so the menu button opens and closes the nav without the app.
- Added `css/static-fixes.css`. It hides the JS-only custom cursor (stuck in the top-left corner) and shows the works-page hero and case-study cards, which the app normally animates in.
- Case-study links (`works/*.html`) weren't captured, so they now open the live pages on heli.studio.
- `og:image` / `twitter:image` now use absolute URLs.

## Known gaps

The zip only has the server-rendered shell: the nav, plus the works-page hero. The main content of Home, About, Services and the three service pages is rendered client-side by JS chunks that weren't downloaded, and the whole `/media/` folder (videos and most images) is missing too. Those pages show only the navigation. To get the full site, re-export it with the missing `/assets/*.js` chunks and `/media/` files, or use the original project source.

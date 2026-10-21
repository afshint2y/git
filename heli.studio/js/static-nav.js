// Minimal replacement for the app's menu toggle; the original React bundle
// (and its lazy-loaded chunks) is not part of this static snapshot.
(function () {
  var btn = document.querySelector('button[aria-label="Open menu"]');
  var pill = document.getElementById('site-navbar-pill');
  if (!btn || !pill) return;
  var panel = pill.children[1];
  btn.addEventListener('click', function () {
    var open = btn.getAttribute('aria-expanded') !== 'true';
    btn.setAttribute('aria-expanded', String(open));
    btn.setAttribute('aria-label', open ? 'Close menu' : 'Open menu');
    pill.style.background = open ? '#111' : '';
    pill.style.color = open ? '#fff' : '';
    panel.style.height = open ? 'auto' : '';
    panel.style.opacity = open ? '1' : '';
    panel.style.paddingBottom = open ? '0.5rem' : '';
  });
})();

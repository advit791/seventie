<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Selenite</title>
<link rel="preconnect" href="https://fonts.googleapis.com">
<link href="https://fonts.googleapis.com/css2?family=Syne:wght@400;600;700;800&family=DM+Sans:wght@300;400;500&display=swap" rel="stylesheet">
<style>
  :root {
    --bg: #0a0a0f;
    --surface: #111118;
    --surface2: #18181f;
    --surface3: #1e1e28;
    --border: rgba(255,255,255,0.07);
    --border2: rgba(255,255,255,0.13);
    --accent: #7c6aff;
    --accent2: #a78bfa;
    --accent-glow: rgba(124,106,255,0.18);
    --text: #f0eeff;
    --text2: #9896b0;
    --text3: #5c5a72;
    --red: #ff5f5f;
    --green: #4ade80;
    --sidebar-w: 72px;
    --radius: 14px;
    --radius-sm: 8px;
  }

  * { margin: 0; padding: 0; box-sizing: border-box; }

  body {
    background: var(--bg);
    color: var(--text);
    font-family: 'DM Sans', sans-serif;
    min-height: 100vh;
    display: flex;
    overflow: hidden;
  }

  /* ── SIDEBAR ── */
  #sidebar {
    width: var(--sidebar-w);
    min-height: 100vh;
    background: var(--surface);
    border-right: 1px solid var(--border);
    display: flex;
    flex-direction: column;
    align-items: center;
    padding: 16px 0;
    gap: 4px;
    flex-shrink: 0;
    z-index: 100;
    position: relative;
  }

  #sidebar .logo {
    width: 38px;
    height: 38px;
    background: var(--accent);
    border-radius: 10px;
    display: flex;
    align-items: center;
    justify-content: center;
    margin-bottom: 12px;
    flex-shrink: 0;
  }

  #sidebar .logo svg { width: 20px; height: 20px; fill: white; }

  .nav-item {
    width: 52px;
    height: 52px;
    border-radius: var(--radius-sm);
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    cursor: pointer;
    gap: 4px;
    transition: background 0.15s, color 0.15s;
    color: var(--text3);
    position: relative;
  }

  .nav-item:hover { background: var(--surface3); color: var(--text2); }
  .nav-item.active { background: var(--accent-glow); color: var(--accent2); }

  .nav-item svg { width: 20px; height: 20px; }
  .nav-item span { font-size: 9px; font-family: 'DM Sans', sans-serif; letter-spacing: 0.03em; }

  #sidebar .spacer { flex: 1; }

  /* ── MAIN ── */
  #main {
    flex: 1;
    display: flex;
    flex-direction: column;
    overflow: hidden;
  }

  /* ── TOPBAR ── */
  #topbar {
    height: 56px;
    background: var(--surface);
    border-bottom: 1px solid var(--border);
    display: flex;
    align-items: center;
    padding: 0 20px;
    gap: 12px;
    flex-shrink: 0;
  }

  #url-bar {
    flex: 1;
    background: var(--surface3);
    border: 1px solid var(--border);
    border-radius: var(--radius-sm);
    height: 34px;
    display: flex;
    align-items: center;
    padding: 0 12px;
    gap: 8px;
    cursor: text;
    transition: border-color 0.15s;
  }

  #url-bar:hover, #url-bar:focus-within { border-color: var(--border2); }
  #url-bar svg { width: 14px; height: 14px; color: var(--text3); flex-shrink: 0; }

  #url-input {
    flex: 1;
    background: none;
    border: none;
    outline: none;
    color: var(--text);
    font-family: 'DM Sans', sans-serif;
    font-size: 13px;
  }

  #url-input::placeholder { color: var(--text3); }

  .top-btn {
    width: 34px;
    height: 34px;
    border-radius: var(--radius-sm);
    background: var(--surface3);
    border: 1px solid var(--border);
    display: flex;
    align-items: center;
    justify-content: center;
    cursor: pointer;
    color: var(--text2);
    transition: background 0.15s, color 0.15s;
    flex-shrink: 0;
  }

  .top-btn:hover { background: var(--surface2); color: var(--text); }
  .top-btn svg { width: 15px; height: 15px; }

  .panic-btn {
    background: rgba(255,95,95,0.12);
    border-color: rgba(255,95,95,0.2);
    color: var(--red);
  }
  .panic-btn:hover { background: rgba(255,95,95,0.22); color: var(--red); }

  #status {
    font-size: 11px;
    color: var(--text3);
    white-space: nowrap;
    font-family: 'DM Sans', sans-serif;
  }

  #status .dot {
    display: inline-block;
    width: 6px;
    height: 6px;
    border-radius: 50%;
    background: var(--green);
    margin-right: 5px;
    vertical-align: middle;
  }

  /* ── CONTENT ── */
  #content {
    flex: 1;
    overflow-y: auto;
    padding: 28px 28px 40px;
    scrollbar-width: thin;
    scrollbar-color: var(--surface3) transparent;
  }

  #content::-webkit-scrollbar { width: 4px; }
  #content::-webkit-scrollbar-track { background: transparent; }
  #content::-webkit-scrollbar-thumb { background: var(--surface3); border-radius: 2px; }

  /* ── SECTION HEADER ── */
  .section-header {
    display: flex;
    align-items: center;
    justify-content: space-between;
    margin-bottom: 16px;
  }

  .section-title {
    font-family: 'Syne', sans-serif;
    font-weight: 700;
    font-size: 17px;
    letter-spacing: -0.02em;
    color: var(--text);
  }

  .see-all {
    font-size: 12px;
    color: var(--accent2);
    cursor: pointer;
    transition: opacity 0.15s;
    text-decoration: none;
  }
  .see-all:hover { opacity: 0.7; }

  /* ── SEARCH BAR ── */
  #search-bar {
    background: var(--surface2);
    border: 1px solid var(--border);
    border-radius: var(--radius);
    height: 46px;
    display: flex;
    align-items: center;
    padding: 0 16px;
    gap: 10px;
    margin-bottom: 28px;
    transition: border-color 0.15s;
  }

  #search-bar:focus-within { border-color: var(--accent); }
  #search-bar svg { width: 16px; height: 16px; color: var(--text3); flex-shrink: 0; }

  #search-input {
    flex: 1;
    background: none;
    border: none;
    outline: none;
    color: var(--text);
    font-family: 'DM Sans', sans-serif;
    font-size: 14px;
  }

  #search-input::placeholder { color: var(--text3); }

  /* ── FEATURED ── */
  #featured {
    background: linear-gradient(135deg, #1a1630 0%, #120f24 100%);
    border: 1px solid rgba(124,106,255,0.2);
    border-radius: var(--radius);
    padding: 24px 28px;
    margin-bottom: 28px;
    display: flex;
    align-items: center;
    justify-content: space-between;
    gap: 16px;
    overflow: hidden;
    position: relative;
  }

  #featured::before {
    content: '';
    position: absolute;
    top: -40px;
    right: -40px;
    width: 160px;
    height: 160px;
    border-radius: 50%;
    background: radial-gradient(circle, rgba(124,106,255,0.15) 0%, transparent 70%);
    pointer-events: none;
  }

  #featured .feat-text h2 {
    font-family: 'Syne', sans-serif;
    font-weight: 800;
    font-size: 22px;
    letter-spacing: -0.03em;
    color: var(--text);
    margin-bottom: 6px;
  }

  #featured .feat-text p {
    font-size: 13px;
    color: var(--text2);
    max-width: 340px;
    line-height: 1.5;
  }

  .play-btn {
    background: var(--accent);
    color: white;
    border: none;
    border-radius: var(--radius-sm);
    padding: 10px 20px;
    font-family: 'DM Sans', sans-serif;
    font-weight: 500;
    font-size: 13px;
    cursor: pointer;
    white-space: nowrap;
    transition: opacity 0.15s, transform 0.1s;
    flex-shrink: 0;
    display: flex;
    align-items: center;
    gap: 8px;
  }

  .play-btn:hover { opacity: 0.85; }
  .play-btn:active { transform: scale(0.97); }
  .play-btn svg { width: 14px; height: 14px; }

  /* ── CARDS GRID ── */
  .cards-grid {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(150px, 1fr));
    gap: 12px;
    margin-bottom: 32px;
  }

  .card {
    background: var(--surface2);
    border: 1px solid var(--border);
    border-radius: var(--radius);
    overflow: hidden;
    cursor: pointer;
    transition: border-color 0.15s, transform 0.15s, background 0.15s;
    position: relative;
  }

  .card:hover {
    border-color: var(--border2);
    transform: translateY(-2px);
    background: var(--surface3);
  }

  .card .thumb {
    width: 100%;
    aspect-ratio: 16/9;
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 32px;
    position: relative;
    overflow: hidden;
  }

  .card .card-info {
    padding: 10px 12px;
  }

  .card .card-name {
    font-size: 13px;
    font-weight: 500;
    color: var(--text);
    margin-bottom: 3px;
    white-space: nowrap;
    overflow: hidden;
    text-overflow: ellipsis;
  }

  .card .card-cat {
    font-size: 11px;
    color: var(--text3);
  }

  .card .badge {
    position: absolute;
    top: 8px;
    right: 8px;
    background: rgba(0,0,0,0.55);
    border-radius: 4px;
    padding: 2px 6px;
    font-size: 10px;
    color: var(--text2);
    backdrop-filter: blur(4px);
  }

  /* ── APP ROWS ── */
  .app-list { display: flex; flex-direction: column; gap: 8px; margin-bottom: 32px; }

  .app-row {
    background: var(--surface2);
    border: 1px solid var(--border);
    border-radius: var(--radius-sm);
    display: flex;
    align-items: center;
    padding: 12px 14px;
    gap: 14px;
    cursor: pointer;
    transition: border-color 0.15s, background 0.15s;
  }

  .app-row:hover { border-color: var(--border2); background: var(--surface3); }

  .app-icon {
    width: 38px;
    height: 38px;
    border-radius: var(--radius-sm);
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 18px;
    flex-shrink: 0;
  }

  .app-row .app-info { flex: 1; min-width: 0; }
  .app-row .app-name { font-size: 14px; font-weight: 500; color: var(--text); }
  .app-row .app-desc { font-size: 12px; color: var(--text3); margin-top: 2px; }

  .app-row .open-icon { color: var(--text3); }
  .app-row .open-icon svg { width: 14px; height: 14px; }

  /* ── BOOKMARKLETS ── */
  .bookmarklet-grid {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(200px, 1fr));
    gap: 10px;
    margin-bottom: 32px;
  }

  .bookmarklet {
    background: var(--surface2);
    border: 1px solid var(--border);
    border-radius: var(--radius-sm);
    padding: 14px;
    cursor: pointer;
    transition: border-color 0.15s, background 0.15s;
  }

  .bookmarklet:hover { border-color: rgba(124,106,255,0.3); background: var(--surface3); }

  .bookmarklet .bm-title { font-size: 13px; font-weight: 500; color: var(--text); margin-bottom: 4px; }
  .bookmarklet .bm-desc { font-size: 11px; color: var(--text3); line-height: 1.4; }

  .bm-icon {
    width: 28px;
    height: 28px;
    border-radius: 6px;
    background: var(--accent-glow);
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 14px;
    margin-bottom: 10px;
  }

  /* ── SETTINGS PANEL ── */
  #settings-panel {
    display: none;
    position: fixed;
    right: 0;
    top: 0;
    height: 100vh;
    width: 300px;
    background: var(--surface);
    border-left: 1px solid var(--border);
    z-index: 200;
    padding: 24px 20px;
    flex-direction: column;
    gap: 20px;
    overflow-y: auto;
  }

  #settings-panel.open { display: flex; }

  .settings-title {
    font-family: 'Syne', sans-serif;
    font-weight: 700;
    font-size: 18px;
    color: var(--text);
    display: flex;
    align-items: center;
    justify-content: space-between;
  }

  .close-btn { cursor: pointer; color: var(--text3); }
  .close-btn:hover { color: var(--text); }
  .close-btn svg { width: 18px; height: 18px; }

  .setting-group {
    background: var(--surface2);
    border: 1px solid var(--border);
    border-radius: var(--radius-sm);
    padding: 14px;
    display: flex;
    flex-direction: column;
    gap: 12px;
  }

  .setting-row {
    display: flex;
    align-items: center;
    justify-content: space-between;
    gap: 10px;
  }

  .setting-label {
    font-size: 13px;
    color: var(--text2);
  }

  .toggle {
    width: 38px;
    height: 22px;
    background: var(--surface3);
    border-radius: 11px;
    cursor: pointer;
    position: relative;
    border: 1px solid var(--border2);
    transition: background 0.2s;
    flex-shrink: 0;
  }

  .toggle.on { background: var(--accent); border-color: var(--accent); }

  .toggle::after {
    content: '';
    position: absolute;
    top: 2px;
    left: 2px;
    width: 16px;
    height: 16px;
    border-radius: 50%;
    background: white;
    transition: left 0.2s;
  }

  .toggle.on::after { left: 18px; }

  .setting-group .group-label {
    font-size: 11px;
    font-weight: 600;
    text-transform: uppercase;
    letter-spacing: 0.08em;
    color: var(--text3);
    margin-bottom: 2px;
  }

  /* ── IFRAME VIEW ── */
  #frame-view {
    display: none;
    position: fixed;
    inset: 0;
    z-index: 300;
    background: var(--bg);
    flex-direction: column;
  }

  #frame-view.open { display: flex; }

  #frame-bar {
    height: 46px;
    background: var(--surface);
    border-bottom: 1px solid var(--border);
    display: flex;
    align-items: center;
    padding: 0 14px;
    gap: 10px;
    flex-shrink: 0;
  }

  #frame-url {
    flex: 1;
    background: var(--surface3);
    border: 1px solid var(--border);
    border-radius: 6px;
    height: 30px;
    font-size: 12px;
    color: var(--text2);
    padding: 0 10px;
    display: flex;
    align-items: center;
    overflow: hidden;
    text-overflow: ellipsis;
    white-space: nowrap;
  }

  #frame-iframe {
    flex: 1;
    border: none;
    background: white;
  }

  /* ── TABS ── */
  .tab-row {
    display: flex;
    gap: 4px;
    margin-bottom: 22px;
  }

  .tab {
    padding: 7px 16px;
    border-radius: 999px;
    font-size: 13px;
    font-weight: 500;
    cursor: pointer;
    color: var(--text3);
    transition: background 0.15s, color 0.15s;
    border: 1px solid transparent;
  }

  .tab:hover { color: var(--text2); }
  .tab.active { background: var(--accent-glow); color: var(--accent2); border-color: rgba(124,106,255,0.2); }

  /* ── PAGE SECTIONS ── */
  .page { display: none; }
  .page.active { display: block; }

  /* ── SCROLLBAR ── */
  * { scrollbar-width: thin; scrollbar-color: var(--surface3) transparent; }

  @media (max-width: 520px) {
    :root { --sidebar-w: 56px; }
    #content { padding: 16px 14px 32px; }
    .cards-grid { grid-template-columns: repeat(auto-fill, minmax(130px, 1fr)); }
    #featured { flex-direction: column; align-items: flex-start; }
    #topbar #status { display: none; }
  }
</style>
</head>
<body>

<!-- SIDEBAR -->
<nav id="sidebar">
  <div class="logo">
    <svg viewBox="0 0 24 24"><path d="M12 2L2 7l10 5 10-5-10-5zM2 17l10 5 10-5M2 12l10 5 10-5"/></svg>
  </div>

  <div class="nav-item active" onclick="setPage('home', this)">
    <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"><path d="M3 9l9-7 9 7v11a2 2 0 01-2 2H5a2 2 0 01-2-2z"/><polyline points="9 22 9 12 15 12 15 22"/></svg>
    <span>home</span>
  </div>

  <div class="nav-item" onclick="setPage('games', this)">
    <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"><rect x="2" y="6" width="20" height="12" rx="2"/><path d="M12 12h.01M8 12h.01M16 12h.01M12 8v8"/></svg>
    <span>games</span>
  </div>

  <div class="nav-item" onclick="setPage('apps', this)">
    <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"><rect x="2" y="2" width="9" height="9" rx="1"/><rect x="13" y="2" width="9" height="9" rx="1"/><rect x="2" y="13" width="9" height="9" rx="1"/><rect x="13" y="13" width="9" height="9" rx="1"/></svg>
    <span>apps</span>
  </div>

  <div class="nav-item" onclick="setPage('bookmarklets', this)">
    <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"><path d="M19 21l-7-5-7 5V5a2 2 0 012-2h10a2 2 0 012 2z"/></svg>
    <span>marks</span>
  </div>

  <div class="spacer"></div>

  <div class="nav-item" onclick="openBlank()">
    <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"><polyline points="15 3 21 3 21 9"/><path d="M10 14L21 3"/><path d="M18 13v6a2 2 0 01-2 2H5a2 2 0 01-2-2V8a2 2 0 012-2h6"/></svg>
    <span>open</span>
  </div>

  <div class="nav-item" onclick="toggleSettings()">
    <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"><circle cx="12" cy="12" r="3"/><path d="M19.07 4.93l-1.41 1.41M6.34 17.66l-1.41 1.41M4.93 4.93l1.41 1.41M17.66 17.66l1.41-1.41M20 12h-1M5 12H4M12 20v-1M12 5V4"/></svg>
    <span>settings</span>
  </div>
</nav>

<!-- MAIN -->
<div id="main">

  <!-- TOPBAR -->
  <div id="topbar">
    <div id="url-bar" onclick="document.getElementById('url-input').focus()">
      <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><circle cx="11" cy="11" r="8"/><path d="m21 21-4.35-4.35"/></svg>
      <input id="url-input" placeholder="Search or enter URL to proxy..." onkeydown="handleUrl(event)">
    </div>
    <div class="top-btn" title="Go" onclick="goUrl()">
      <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round"><line x1="5" y1="12" x2="19" y2="12"/><polyline points="12 5 19 12 12 19"/></svg>
    </div>
    <div class="top-btn panic-btn" title="Panic!" onclick="panicRedirect()" id="panic">
      <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round"><polygon points="7.86 2 16.14 2 22 7.86 22 16.14 16.14 22 7.86 22 2 16.14 2 7.86"/><line x1="12" y1="8" x2="12" y2="12"/><line x1="12" y1="16" x2="12.01" y2="16"/></svg>
    </div>
    <div id="status"><span class="dot"></span><span id="online-count">--</span> online &nbsp;|&nbsp; <span id="clock">--:-- --</span></div>
  </div>

  <!-- CONTENT -->
  <div id="content">

    <!-- HOME PAGE -->
    <div id="page-home" class="page active">
      <div id="featured">
        <div class="feat-text">
          <h2>Play Anything, Anywhere</h2>
          <p>Unblocked games, apps, and a fast web proxy — right in your browser, no installs needed.</p>
        </div>
        <button class="play-btn" onclick="setPage('games', document.querySelector('[onclick*=games]'))">
          <svg viewBox="0 0 24 24" fill="white" stroke="none"><polygon points="5 3 19 12 5 21 5 3"/></svg>
          Browse Games
        </button>
      </div>

      <div class="section-header">
        <span class="section-title">Popular Games</span>
        <a class="see-all" onclick="setPage('games', document.querySelector('[onclick*=games]'))">See all →</a>
      </div>
      <div class="cards-grid" id="home-games"></div>

      <div class="section-header">
        <span class="section-title">Featured Apps</span>
        <a class="see-all" onclick="setPage('apps', document.querySelector('[onclick*=apps]'))">See all →</a>
      </div>
      <div class="app-list" id="home-apps"></div>
    </div>

    <!-- GAMES PAGE -->
    <div id="page-games" class="page">
      <div id="search-bar">
        <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><circle cx="11" cy="11" r="8"/><path d="m21 21-4.35-4.35"/></svg>
        <input id="search-input" placeholder="Search games..." oninput="filterGames(this.value)">
      </div>
      <div class="tab-row" id="game-tabs"></div>
      <div class="cards-grid" id="games-grid"></div>
    </div>

    <!-- APPS PAGE -->
    <div id="page-apps" class="page">
      <div class="section-header" style="margin-bottom:20px">
        <span class="section-title">Apps</span>
      </div>
      <div class="app-list" id="apps-list"></div>
    </div>

    <!-- BOOKMARKLETS PAGE -->
    <div id="page-bookmarklets" class="page">
      <div class="section-header" style="margin-bottom:20px">
        <span class="section-title">Bookmarklets</span>
      </div>
      <div class="bookmarklet-grid" id="bm-grid"></div>
    </div>

  </div>
</div>

<!-- SETTINGS PANEL -->
<div id="settings-panel">
  <div class="settings-title">
    Settings
    <div class="close-btn" onclick="toggleSettings()">
      <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><line x1="18" y1="6" x2="6" y2="18"/><line x1="6" y1="6" x2="18" y2="18"/></svg>
    </div>
  </div>

  <div class="setting-group">
    <div class="group-label">Cloaking</div>
    <div class="setting-row">
      <span class="setting-label">Tab Cloak</span>
      <div class="toggle" id="toggle-cloak" onclick="toggleOption('cloak', this)"></div>
    </div>
    <div class="setting-row">
      <span class="setting-label">Auto Cloak on Launch</span>
      <div class="toggle" id="toggle-auto" onclick="toggleOption('auto', this)"></div>
    </div>
  </div>

  <div class="setting-group">
    <div class="group-label">Panic Button</div>
    <div class="setting-row">
      <span class="setting-label">Redirect URL</span>
    </div>
    <input id="panic-url" value="https://classroom.google.com" style="background:var(--surface3);border:1px solid var(--border);border-radius:6px;padding:8px 12px;color:var(--text);font-family:'DM Sans',sans-serif;font-size:13px;width:100%;outline:none;">
  </div>

  <div class="setting-group">
    <div class="group-label">Performance</div>
    <div class="setting-row">
      <span class="setting-label">Fast Mode</span>
      <div class="toggle on" id="toggle-fast" onclick="toggleOption('fast', this)"></div>
    </div>
  </div>

  <div class="setting-group">
    <div class="group-label">Theme</div>
    <div style="display:flex;gap:8px;flex-wrap:wrap;margin-top:4px;">
      <div onclick="setTheme('#7c6aff')" style="width:28px;height:28px;border-radius:50%;background:#7c6aff;cursor:pointer;border:2px solid var(--border2)"></div>
      <div onclick="setTheme('#06b6d4')" style="width:28px;height:28px;border-radius:50%;background:#06b6d4;cursor:pointer;border:2px solid var(--border2)"></div>
      <div onclick="setTheme('#f472b6')" style="width:28px;height:28px;border-radius:50%;background:#f472b6;cursor:pointer;border:2px solid var(--border2)"></div>
      <div onclick="setTheme('#4ade80')" style="width:28px;height:28px;border-radius:50%;background:#4ade80;cursor:pointer;border:2px solid var(--border2)"></div>
      <div onclick="setTheme('#fb923c')" style="width:28px;height:28px;border-radius:50%;background:#fb923c;cursor:pointer;border:2px solid var(--border2)"></div>
    </div>
  </div>
</div>

<!-- FRAME VIEW -->
<div id="frame-view">
  <div id="frame-bar">
    <div class="top-btn" onclick="closeFrame()" title="Back">
      <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round"><line x1="19" y1="12" x2="5" y2="12"/><polyline points="12 19 5 12 12 5"/></svg>
    </div>
    <div id="frame-url">about:blank</div>
    <div class="top-btn" onclick="reloadFrame()">
      <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><polyline points="1 4 1 10 7 10"/><path d="M3.51 15a9 9 0 1 0 .49-4.47"/></svg>
    </div>
    <div class="top-btn" onclick="fullscreenFrame()">
      <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><polyline points="15 3 21 3 21 9"/><polyline points="9 21 3 21 3 15"/><line x1="21" y1="3" x2="14" y2="10"/><line x1="3" y1="21" x2="10" y2="14"/></svg>
    </div>
  </div>
  <iframe id="frame-iframe" sandbox="allow-scripts allow-same-origin allow-forms allow-popups"></iframe>
</div>

<script>
const GAMES = [
  { name: "Slope", cat: "Action", emoji: "🎿", color: "#1a1f3a", tags: ["action","popular"] },
  { name: "Run 3", cat: "Runner", emoji: "🏃", color: "#1a2e1a", tags: ["runner","popular"] },
  { name: "1v1.LOL", cat: "Battle", emoji: "🏗️", color: "#2a1a1a", tags: ["battle","popular"] },
  { name: "Retro Bowl", cat: "Sports", emoji: "🏈", color: "#2a1e10", tags: ["sports"] },
  { name: "Drift Boss", cat: "Racing", emoji: "🚗", color: "#1a1a2e", tags: ["racing"] },
  { name: "Tunnel Rush", cat: "Arcade", emoji: "🌀", color: "#1a2a2a", tags: ["arcade","popular"] },
  { name: "Moto X3M", cat: "Racing", emoji: "🏍️", color: "#2e1a1a", tags: ["racing"] },
  { name: "Snake Game", cat: "Classic", emoji: "🐍", color: "#0a2a0a", tags: ["classic"] },
  { name: "2048", cat: "Puzzle", emoji: "🔢", color: "#2a1a2a", tags: ["puzzle","classic"] },
  { name: "Tetris", cat: "Classic", emoji: "🧩", color: "#0a1a2e", tags: ["classic","popular"] },
  { name: "Flappy Bird", cat: "Arcade", emoji: "🐦", color: "#0a2a1a", tags: ["arcade"] },
  { name: "Fireboy & Watergirl", cat: "Puzzle", emoji: "🔥", color: "#2a0a0a", tags: ["puzzle"] },
  { name: "Happy Wheels", cat: "Action", emoji: "🎡", color: "#2a2a0a", tags: ["action"] },
  { name: "Minecraft Classic", cat: "Sandbox", emoji: "⛏️", color: "#1a2e1a", tags: ["sandbox","popular"] },
  { name: "Basketball Stars", cat: "Sports", emoji: "🏀", color: "#2e1a0a", tags: ["sports"] },
  { name: "Geometry Dash", cat: "Rhythm", emoji: "🎵", color: "#1a0a2e", tags: ["rhythm","popular"] },
];

const APPS = [
  { name: "Google", icon: "🌐", color: "#1a2035", desc: "Search the web", url: "https://google.com" },
  { name: "YouTube", icon: "▶️", color: "#2a1010", desc: "Watch videos", url: "https://youtube.com" },
  { name: "Spotify", icon: "🎵", color: "#0a2a0a", desc: "Stream music", url: "https://spotify.com" },
  { name: "Discord", icon: "💬", color: "#1a1a3a", desc: "Chat and voice", url: "https://discord.com" },
  { name: "Reddit", icon: "🤖", color: "#2a1a0a", desc: "Browse communities", url: "https://reddit.com" },
  { name: "Wikipedia", icon: "📖", color: "#1a1a1a", desc: "Free encyclopedia", url: "https://wikipedia.org" },
  { name: "Scratch", icon: "🐱", color: "#1a2510", desc: "Code projects", url: "https://scratch.mit.edu" },
  { name: "Khan Academy", icon: "🎓", color: "#0a1e2a", desc: "Learn anything", url: "https://khanacademy.org" },
];

const BOOKMARKLETS = [
  { icon: "🔍", title: "Dark Mode Toggle", desc: "Instantly toggle dark mode on any website" },
  { icon: "📋", title: "Copy All Text", desc: "Copy all visible text on the page to clipboard" },
  { icon: "🔗", title: "Extract Links", desc: "List every hyperlink on the current page" },
  { icon: "🖨️", title: "Print Page", desc: "Open the print dialog for any page" },
  { icon: "🔤", title: "Increase Font", desc: "Make text bigger on any website" },
  { icon: "📏", title: "Page Ruler", desc: "Measure elements and layout on screen" },
  { icon: "🕵️", title: "Wayback Machine", desc: "View archived versions of this page" },
  { icon: "🔑", title: "Show Passwords", desc: "Reveal hidden password fields" },
];

const GAME_TAGS = ["all", "popular", "action", "runner", "racing", "arcade", "puzzle", "classic", "sports", "battle", "sandbox", "rhythm"];

let currentTag = "all";
let allGamesFiltered = [...GAMES];

function renderHomeGames() {
  const popular = GAMES.filter(g => g.tags.includes("popular")).slice(0, 6);
  document.getElementById("home-games").innerHTML = popular.map(gameCard).join("");
}

function renderHomeApps() {
  document.getElementById("home-apps").innerHTML = APPS.slice(0, 4).map(appRow).join("");
}

function gameCard(g) {
  return `<div class="card" onclick="openGame('${g.name}')">
    <div class="thumb" style="background:${g.color}">
      <span style="font-size:36px">${g.emoji}</span>
    </div>
    <div class="card-info">
      <div class="card-name">${g.name}</div>
      <div class="card-cat">${g.cat}</div>
    </div>
  </div>`;
}

function appRow(a) {
  return `<div class="app-row" onclick="openApp('${a.url}', '${a.name}')">
    <div class="app-icon" style="background:${a.color}">${a.icon}</div>
    <div class="app-info">
      <div class="app-name">${a.name}</div>
      <div class="app-desc">${a.desc}</div>
    </div>
    <div class="open-icon">
      <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.8" stroke-linecap="round"><polyline points="9 18 15 12 9 6"/></svg>
    </div>
  </div>`;
}

function renderGameTabs() {
  document.getElementById("game-tabs").innerHTML = GAME_TAGS.map(t =>
    `<div class="tab${t === currentTag ? " active" : ""}" onclick="filterByTag('${t}')">${t}</div>`
  ).join("");
}

function renderGamesGrid(list) {
  document.getElementById("games-grid").innerHTML = list.map(gameCard).join("");
}

function filterByTag(tag) {
  currentTag = tag;
  renderGameTabs();
  const query = document.getElementById("search-input").value.toLowerCase();
  applyFilters(query, tag);
}

function filterGames(q) {
  applyFilters(q.toLowerCase(), currentTag);
}

function applyFilters(q, tag) {
  let list = GAMES;
  if (tag !== "all") list = list.filter(g => g.tags.includes(tag));
  if (q) list = list.filter(g => g.name.toLowerCase().includes(q) || g.cat.toLowerCase().includes(q));
  renderGamesGrid(list);
}

function renderApps() {
  document.getElementById("apps-list").innerHTML = APPS.map(appRow).join("");
}

function renderBookmarklets() {
  document.getElementById("bm-grid").innerHTML = BOOKMARKLETS.map(b => `
    <div class="bookmarklet" onclick="alert('Drag this to your bookmarks bar to use it!')">
      <div class="bm-icon">${b.icon}</div>
      <div class="bm-title">${b.title}</div>
      <div class="bm-desc">${b.desc}</div>
    </div>
  `).join("");
}

function setPage(page, el) {
  document.querySelectorAll(".page").forEach(p => p.classList.remove("active"));
  document.getElementById("page-" + page).classList.add("active");
  document.querySelectorAll(".nav-item").forEach(n => n.classList.remove("active"));
  if (el) el.classList.add("active");
}

function toggleSettings() {
  document.getElementById("settings-panel").classList.toggle("open");
}

function toggleOption(key, el) {
  el.classList.toggle("on");
  if (key === "cloak") {
    if (el.classList.contains("on")) {
      document.title = "Google Classroom";
      const link = document.querySelector("link[rel='icon']") || document.createElement("link");
      link.rel = "icon";
      link.href = "https://ssl.gstatic.com/classroom/favicon.png";
      document.head.appendChild(link);
    } else {
      document.title = "Selenite";
    }
  }
}

function setTheme(color) {
  document.documentElement.style.setProperty("--accent", color);
  const rgb = parseInt(color.slice(1), 16);
  const r = (rgb >> 16) & 255, g = (rgb >> 8) & 255, b = rgb & 255;
  document.documentElement.style.setProperty("--accent-glow", `rgba(${r},${g},${b},0.18)`);
  document.documentElement.style.setProperty("--accent2", lighten(color, 30));
}

function lighten(hex, amount) {
  const num = parseInt(hex.slice(1), 16);
  let r = (num >> 16) + amount, g = ((num >> 8) & 0xff) + amount, b = (num & 0xff) + amount;
  return "#" + [Math.min(r,255), Math.min(g,255), Math.min(b,255)].map(c => c.toString(16).padStart(2,"0")).join("");
}

function panicRedirect() {
  const url = document.getElementById("panic-url")?.value || "https://classroom.google.com";
  window.location.replace(url);
}

function openBlank() {
  window.open("about:blank", "_blank");
}

function openGame(name) {
  const proxyUrls = {
    "Slope": "https://slope-unblocked.github.io/",
    "Run 3": "https://run-3-unblocked.github.io/",
  };
  const url = proxyUrls[name] || `https://www.google.com/search?q=${encodeURIComponent(name + " unblocked")}`;
  openFrame(url, name);
}

function openApp(url, name) {
  openFrame(url, name);
}

function openFrame(url, title) {
  document.getElementById("frame-url").textContent = url;
  document.getElementById("frame-iframe").src = url;
  document.getElementById("frame-view").classList.add("open");
}

function closeFrame() {
  document.getElementById("frame-view").classList.remove("open");
  document.getElementById("frame-iframe").src = "about:blank";
}

function reloadFrame() {
  const f = document.getElementById("frame-iframe");
  f.src = f.src;
}

function fullscreenFrame() {
  const f = document.getElementById("frame-iframe");
  if (f.requestFullscreen) f.requestFullscreen();
}

function handleUrl(e) {
  if (e.key === "Enter") goUrl();
}

function goUrl() {
  let val = document.getElementById("url-input").value.trim();
  if (!val) return;
  let url = val;
  if (!val.startsWith("http")) {
    if (val.includes(".") && !val.includes(" ")) {
      url = "https://" + val;
    } else {
      url = "https://www.google.com/search?q=" + encodeURIComponent(val);
    }
  }
  openFrame(url, val);
}

function updateClock() {
  const now = new Date();
  let h = now.getHours(), m = String(now.getMinutes()).padStart(2,"0"), s = String(now.getSeconds()).padStart(2,"0");
  const ampm = h >= 12 ? "pm" : "am";
  h = h % 12 || 12;
  document.getElementById("clock").textContent = `${h}:${m}:${s} ${ampm}`;
}

function updateOnline() {
  document.getElementById("online-count").textContent = Math.floor(Math.random() * 200 + 120);
}

// Init
renderHomeGames();
renderHomeApps();
renderGamesGrid(GAMES);
renderGameTabs();
renderApps();
renderBookmarklets();
updateClock();
updateOnline();
setInterval(updateClock, 1000);
setInterval(updateOnline, 30000);
</script>
</body>
</html>

---
title: Home
hide:
    - navigation
    - toc
    - footer
---

<style>
:root {
    --primary-color: #458F94;
}

.md-content__inner {
    margin: 0;
}

.md-main__inner {
    margin-top: 0;
}

.md-typeset h1 {
    margin: 0;
}

.landing-container {
    display: flex;
    width: 100%;
    height: 100%;
    max-width: 1600px;
    margin: 0 auto;
}

.content-side {
    flex: 1;
    padding: 0.5rem 2rem 3rem 0;
    display: flex;
    flex-direction: column;
    justify-content: center;
}

.logo {
    margin-bottom: 1.1rem;
    display: flex;
    align-items: center;
    gap: 0.5rem;
}

.logo svg {
    width: auto;
    height: 48px;
}

.logo-text {
    color: var(--primary-color);
    font-family: "QTAvanti";
    font-size: 3em;
}

.tagline {
    font-size: 1.1em;
    color: var(--dimmed-text-color);
    font-weight: 400;
}

.features {
    display: grid;
    grid-template-columns: repeat(2, 1fr);
    gap: 0.5rem;
    margin-bottom: 3.25rem;
    margin-top: 1.25rem;
}

.feature {
    display: flex;
    align-items: flex-start;
    gap: .75rem;
}

.feature-icon {
    color: #000;
    background: var(--primary-color);
    background: linear-gradient(202deg,rgba(125, 180, 189, 1) 0%, var(--primary-color) 50%);
    width: 32px;
    height: 32px;
    border-radius: 8px;
    display: flex;
    align-items: center;
    justify-content: center;
    flex-shrink: 0;
}

.feature-text {
    font-size: 0.7rem;
    line-height: 1.4;
}

.feature-text p {
    margin-top: 8px;
}

.buttons {
    display: flex;
    gap: 1rem;
}

.btn {
    display: inline-flex;
    align-items: center;
    gap: .5rem;
    padding: .45rem 1.2rem;
    border-radius: 8px;
    font-weight: 600;
    font-size: 1rem;
    text-decoration: none;
    transition: .2s;
}

.btn-download {
    color: var(--button-text-color);
    background-color: var(--primary-color);
    border: 1px solid var(--primary-color-dark)
}

.btn:hover {
    color: var(--background-color);
    transform: translateY(-1px);
    box-shadow: 0 12px 14px -8px var(--button-shadow-color);
    transition: .1s;
}

.btn:active {
    background-color: var(--primary-color-dark);
    transform: translateY(1px);
    transition: .1s;
    box-shadow: none;
}

.btn-external {
    color: var(--text-color);
    background-color: var(--background-color-light);
    border: 1px solid var(--border-color);
}

.btn-external:hover {
    color: var(--dimmed-text-color);
}

.btn-external:active {
    color: var(--text-color);
    background-color: var(--background-color-dark);
}

.preview-side {
    flex: 1;
    display: flex;
    align-items: center;
    justify-content: flex-start;
    position: relative;
    overflow: visible;
}

.cover-image {
    width: 100%;
}

.copyright-line {
    margin-top: 0.5rem;
}

.gh-logo {
    margin-left: auto;
    margin-top: auto;
    margin-bottom: auto;
    cursor: pointer;
}

.gh-logo img {
    height: 22px;
}

@media (max-width: 1100px) {
    .landing-container {
        flex-direction: column;
    }
    
    .content-side {
        padding: 4rem;
    }
    
    .preview-side {
        display: none;
    }
    
    .features {
        gap: 1rem;
    }
}
</style>

<div class="landing-container">
    <div class="content-side">
        <div class="logo">
            <img src="assets/logo256.png" width="80" height="80">
            <span class="logo-text">Polly</span>
        </div>
        <h1>Minimalistic 2D C++ Game Framework</h1>
        <p class="tagline">Get started with C++ and 2D game development using a clean, modern API.</p>
        <div class="features">
            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-app-window-mac-icon lucide-app-window-mac"><rect width="20" height="16" x="2" y="4" rx="2"></rect><path d="M6 8h.01"></path><path d="M10 8h.01"></path><path d="M14 8h.01"></path></svg>
                </div>
                <div class="feature-text">
                    <strong>Cross-Platform</strong>
                    <p>
                    Runs on multiple platforms, including Windows, macOS, Linux, Android and iOS. 
                    </p>
                </div>
            </div>

            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-bird-icon lucide-bird"><path d="M16 7h.01"></path><path d="M3.4 18H12a8 8 0 0 0 8-8V7a4 4 0 0 0-7.28-2.3L2 20"></path><path d="m20 7 2 .5-2 .5"></path><path d="M10 18v3"></path><path d="M14 17.75V21"></path><path d="M7 18a6 6 0 0 0 3.84-10.61"></path></svg>
                </div>
                <div class="feature-text">
                    <strong>Free and Open Source</strong>
                    <p>
                    <a href="https://www.gnu.org/licenses/gpl-3.0.en.html" target="_blank">GPLv3</a> for the framework itself, <a href="https://opensource.org/license/mit" target="_blank">MIT</a> for games built with it. No royalty share. 
                    </p>
                </div>
            </div>

            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-braces-icon lucide-braces"><path d="M8 3H7a2 2 0 0 0-2 2v5a2 2 0 0 1-2 2 2 2 0 0 1 2 2v5c0 1.1.9 2 2 2h1"></path><path d="M16 21h1a2 2 0 0 0 2-2v-5c0-1.1.9-2 2-2a2 2 0 0 1-2-2V5a2 2 0 0 0-2-2h-1"></path></svg>
                </div>
                <div class="feature-text">
                    <strong>Modern and Portable C++</strong>
                    <p>
                    Improved C++ types and containers, providing an ergonomic API and safety guarantees by default. 
                    </p>
                </div>
            </div>

            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-gpu-icon lucide-gpu"><path d="M2 21V3"></path><path d="M2 5h18a2 2 0 0 1 2 2v8a2 2 0 0 1-2 2H2.26"></path><path d="M7 17v3a1 1 0 0 0 1 1h5a1 1 0 0 0 1-1v-3"></path><circle cx="16" cy="11" r="2"></circle><circle cx="8" cy="11" r="2"></circle></svg>
                </div>
                <div class="feature-text">
                    <strong>Efficient 2D Rendering</strong>
                    <p>
                    Automatic batching and direct use of the platform's native graphics API such as Direct3D, OpenGL and Metal. 
                    </p>
                </div>
            </div>

            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-audio-lines-icon lucide-audio-lines"><path d="M2 10v3"></path><path d="M6 6v11"></path><path d="M10 3v18"></path><path d="M14 8v7"></path><path d="M18 5v13"></path><path d="M22 10v3"></path></svg>
                </div>
                <div class="feature-text">
                    <strong>Audio</strong>
                    <p>
                    Easy-to-use audio API, including faders and channels for playback control. 
                    </p>
                </div>
            </div>

            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-paintbrush-icon lucide-paintbrush"><path d="m14.622 17.897-10.68-2.913"></path><path d="M18.376 2.622a1 1 0 1 1 3.002 3.002L17.36 9.643a.5.5 0 0 0 0 .707l.944.944a2.41 2.41 0 0 1 0 3.408l-.944.944a.5.5 0 0 1-.707 0L8.354 7.348a.5.5 0 0 1 0-.707l.944-.944a2.41 2.41 0 0 1 3.408 0l.944.944a.5.5 0 0 0 .707 0z"></path><path d="M9 8c-1.804 2.71-3.97 3.46-6.583 3.948a.507.507 0 0 0-.302.819l7.32 8.883a1 1 0 0 0 1.185.204C12.735 20.405 16 16.792 16 15"></path></svg>
                </div>
                <div class="feature-text">
                    <strong>Custom Shaders</strong>
                    <p>
                    Simple and safe shading language that compiles to native shading languages. 
                    </p>
                </div>
            </div>

            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-package-icon lucide-package"><path d="M11 21.73a2 2 0 0 0 2 0l7-4A2 2 0 0 0 21 16V8a2 2 0 0 0-1-1.73l-7-4a2 2 0 0 0-2 0l-7 4A2 2 0 0 0 3 8v8a2 2 0 0 0 1 1.73z"></path><path d="M12 22V12"></path><polyline points="3.29 7 12 12 20.71 7"></polyline><path d="m7.5 4.27 9 5.15"></path></svg>
                </div>
                <div class="feature-text">
                    <strong>Content Management</strong>
                    <p>
                    Supports formats such as PNG, JPG, WAV, MP3, FLAC and much more. Assets are automatically packed during build.
                    </p>
                </div>
            </div>

            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-sparkles-icon lucide-sparkles"><path d="M11.017 2.814a1 1 0 0 1 1.966 0l1.051 5.558a2 2 0 0 0 1.594 1.594l5.558 1.051a1 1 0 0 1 0 1.966l-5.558 1.051a2 2 0 0 0-1.594 1.594l-1.051 5.558a1 1 0 0 1-1.966 0l-1.051-5.558a2 2 0 0 0-1.594-1.594l-5.558-1.051a1 1 0 0 1 0-1.966l5.558-1.051a2 2 0 0 0 1.594-1.594z"></path><path d="M20 2v4"></path><path d="M22 4h-4"></path><circle cx="4" cy="20" r="2"></circle></svg>
                </div>
                <div class="feature-text">
                    <strong>Particle Systems</strong>
                    <p>
                    Flexible 2D particle systems, customizable behaviors via emitters, modifiers and shapes. 
                    </p>
                </div>
            </div>

            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-person-standing-icon lucide-person-standing"><circle cx="12" cy="5" r="1"></circle><path d="m9 20 3-6 3 6"></path><path d="m6 8 6 2 6-2"></path><path d="M12 10v4"></path></svg>
                </div>
                <div class="feature-text">
                    <strong>Spine Integration</strong>
                    <a href="https://esotericsoftware.com/" target="_blank">Spine</a> integration for powerful physics-based skeletal 2D animations. 
                </div>
            </div>

            <div class="feature">
                <div class="feature-icon">
                    <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="#fff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-layout-template-icon lucide-layout-template"><rect width="18" height="7" x="3" y="3" rx="1"></rect><rect width="9" height="7" x="3" y="14" rx="1"></rect><rect width="5" height="7" x="16" y="14" rx="1"></rect></svg>
                </div>
                <div class="feature-text">
                    <strong>Dear ImGui</strong>
                    <p>
                    C++ idiomatic <a href="https://github.com/ocornut/imgui" target="_blank">Dear ImGui</a> integration for rapid prototyping and UI. 
                    </p>
                </div>
            </div>
        </div>
        <!--
        <div class="buttons">
            <a class="btn btn-download" href="docs/index.html">
                <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="lucide lucide-play-icon lucide-play"><path d="M5 5a2 2 0 0 1 3.008-1.728l11.997 6.998a2 2 0 0 1 .003 3.458l-12 7A2 2 0 0 1 5 19z"/></svg>
                Get Started
            </a>
            <a class="btn btn-external" href="https://github.com/cdervis/Polly" target="_blank">
                <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none"
                     stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"
                     class="lucide lucide-github-icon lucide-github">
                    <path d="M15 22v-4a4.8 4.8 0 0 0-1-3.5c3 0 6-2 6-5.5.08-1.25-.27-2.48-1-3.5.28-1.15.28-2.35 0-3.5 0 0-1 0-3 1.5-2.64-.5-5.36-.5-8 0C6 2 5 2 5 2c-.3 1.15-.3 2.35 0 3.5A5.403 5.403 0 0 0 4 9c0 3.5 3 5.5 6 5.5-.39.49-.68 1.05-.85 1.65-.17.6-.22 1.23-.15 1.85v4"/>
                    <path d="M9 18c-4.51 2-5-2-7-2"/>
                </svg>
                GitHub
            </a>
        </div>
        -->
        
    </div>
    <div class="preview-side">
        <img class="cover-image" src="assets/cover.webp#only-light">
        <img class="cover-image" src="assets/cover-dark.webp#only-dark">
    </div>
</div>
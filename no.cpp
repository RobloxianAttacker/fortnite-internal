#include <includes.h>
#include <no_hook/no_hook.h>
#include <no_define.h>
#include <no_loop.h>

void functions_line(int x, int y, int x2, int y2, no_menu::color c) noexcept
{
	color cool_col(c.a, c.r, c.g, c.b);
	gui.draw_line(x, y, x2, y2, cool_col);
}

void functions_rect(int x, int y, int x2, int y2, no_menu::color c) noexcept
{
	color cool_col(c.a, c.r, c.g, c.b);
	gui.draw_rect(x, y, x2, y2, cool_col);
}

void functions_filled_rect(int x, int y, int x2, int y2, no_menu::color c) noexcept
{
	color cool_col(c.a, c.r, c.g, c.b);
	gui.fill_rect(x, y, x2, y2, cool_col);
}

const wchar_t* CharToWchar(const char* ch)
{
	const size_t len = strlen(ch) + 1;
	wchar_t* wch = new wchar_t[len];
	mbstowcs(wch, ch, len);
	return wch;
}

UINT32 ColorToUint32(const no_menu::color color)
{
	UINT32 result =
		(BYTE(color.a) << 24) +
		(BYTE(color.r) << 16) +
		(BYTE(color.g) << 8) +
		BYTE(color.b);
	return result;
}

void functions_text(int x, int y, no_menu::color color, bool center, const char* text) noexcept
{
	if (pFontWrapper) {
		char* yh = (char*)text;
		const size_t cSize = strlen(yh) + 1;
		wchar_t* wc = new wchar_t[cSize];
		size_t tmp = 0;
		mbstowcs_s(&tmp, wc, cSize, yh, cSize);

		pFontWrapper->DrawString(pContext, wc, 14, x, y, ColorToUint32(color), FW1_RESTORESTATE);
	}
}

float functions_get_frametime() noexcept
{
	return 60.f;
}

short functions_oGetAsyncKeyState(int key_to_get) noexcept {
	return SDK::Syscall::NtGetAsyncKeyState(key_to_get);
}
e
{er
	freopen_s(&fp, _("CONOUT$"), _("w"), stdout);
}

auto InitOnce() -> void
{erfunctions_get_text_size;erger
	no_menu::functions.get_frametime = functions_get_frametime;
	no_menu::functions.get_key_state_discord = functions_oGetAsyncKeyState;
}

HRESULT present_hooked(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (firstTime)
	{
		pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice);
		pDevice->GetImmediateContext(&pContext);

		HRESULT hResult = FW1CreateFactory(FW1_VERSION, &pFW1Factory);
		hResult = pFW1Factory->CreateFontWrapper(pDevice, _(L"Tahoma"), &pFontWrapper);
		pFW1Factory->Release();

		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pSwapChain->GetDevice(__uuidof(pDevice), (void**)&pDevice);
			pDevice->GetImmediateContext(&pContext);
		}

		if (SUCCEEDED(pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&RenderTargetTexture)))
		{
			pDevice->CreateRenderTargetView(RenderTargetTexture, NULL, &RenderTargetView);
			RenderTargetTexture->Release();gerger
			pDevice->Release();
		}

		InitOnce(); //only once
		gui.init(pSwapChain);gewrgerger

		firstTime = false;
	}

	if (!RenderTargetView)
	{
		pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice);

		if (!pDevice) return false;

		pDevice->GetImmediateContext(&pContext);

		if (!pContext) return false;

		if (SUCCEEDED(pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&RenderTargetTexture)))
		{
			pDevice->CreateRenderTargetView(RenderTargetTexture, NULL, &RenderTargetView);
			RenderTargetTexture->Release();
			pDevice->Release();
		}
	}

	if (RenderTargetView)
	{
		pContext->RSGetViewports(&vps, &viewport);
		X = viewport.Width;
		Y = viewport.Height;

		pContext->OMSetRenderTargets(1, &RenderTargetView, NULL);

		gui.begin_scene();
		{
			no_menu::window_input(_("UnrealWindow"), _("Fortnite  "));

			if (no_menu::begin_window(_("Chea.to | v3"), no_menu::vec2({ 545, 580 }), VK_INSERT, no_menu::no_menu_window_flags_none))
			{

				if (tab == 1) { tab1 = true; tab2 = false; tab3 = false; tab4 = false; }
				no_menu::Lineee(no_menu::vec2({ 120, 4 }), tab1); if (no_menu::button(_("Aimbot"), no_menu::vec2({ 120, 37 }))regverwgerg) { tab = 1; }

				no_menu::next_column(130, 0);

				if (tab == 2) { tab1 = false; tab2 = true; tab3 = false; tab4 = false; }
				no_menu::Lineee(no_menu::vec2({ 120, 4 }), tab2); if (no_menu::button(_("ESP"), no_menu::vec2({ 120, 37 }))) { tab = 2; }

				no_menu::next_column(130, 0);

				if (tab == 3) { tab1 = false; tab2 = false; tab3 = true; tab4 = false; }
				no_menu::Lineee(no_menu::vec2({ 120, 4 }), tab3); if (no_menu::button(_("Exploits"), no_menu::vec2({ 120, 37 }))) { tab = 3; }

				no_menu::next_column(130, 0);

				if (tab == 4) { tab1 = false; tab2 = false; tab3 = false; tab4 = true; }
				no_menu::Lineee(no_menu::vec2({ 120, 4 }), tab4); if (no_menu::button(_("Misc"), no_menu::vec2({ 120, 37 }))) { tab = 4; }

				no_menu::back_column(390, 50);

				if (tab == 1) no_menu::begin_groupbox(_("Aimbot"), no_menu::vec2({ 513, 480 }));
				if (tab == 2) no_menu::begin_groupbox(_("ESP"), no_menu::vec2({ 513, 480 }));
				if (tab == 3) no_menu::begin_groupbox(_("Exploits(D)"), no_menu::vec2({ 513, 480 }));
				if (tab == 4) no_menu::begin_groupbox(_("Misc"), no_menu::vec2({ 513, 480 }));


				if (tab == 1) {
					no_menu::checkbox(_("Enable Aimbot"), Settings::Aimbot);
					UI_Help::AimbotTab::Aimbot();

					no_menu::separator(10, false);
					no_menu::slider_int(_("Aimbot Fov"), 10.f, 999.f, Settings::AimbotFovCircle);
					UI_Help::AimbotTab::AimbotFov();

					no_menu::separator(10, false);
					no_menu::slider_int(_("Aimbot Smooth"), 3.0f, 20.f, Settings::AimbotSmooth);
					UI_Help::AimbotTab::AimbotSmooth();

					no_menu::separator(10, false);
					no_menu::combobox(_("Aimbot Bone"), AimbotBone, Settings::AimbotBone_Value);
					UI_Help::AimbotTab::AimbotBone();

					no_menu::separator(10, false);
					no_menu::checkbox(_("Aimbot Prediction"), Settings::AimbotPrediction);
					UI_Help::AimbotTab::AimbotPrediction();
				}

				if (tab == 2) {
					no_menu::checkbox(_("Box ESP"), Settings::ESP);
					UI_Help::ESPTab::ESP();

					no_menu::separator(10, false);
					no_menu::checkbox(_("Skeleton"), Settings::ESP_Skeleton);
					UI_Help::ESPTab::SKELETON();

					no_menu::separator(10, false);
					no_menu::checkbox(_("Lines"), Settings::ESP_Lines);

					//	no_menu::separator(10, false);
					//	no_menu::checkbox(_("Name ESP"), Settings::NameESP);

					no_menu::separator(10, false);
					no_menu::checkbox(_("Aiming Line"), Settings::ESP_AimingLines);

					no_menu::separator(10, false);erghoierwoihgohierhoi
					no_menu::checkbox(_("LLama"), Settings::ESP_Llama);

					no_menu::separator(10, false);
					no_menu::checkbox(_("Vehicle"), Settings::ESP_Vehicle);
				}

				if (tab == 3) {
					no_menu::checkbox(_("Aim While Jumping"), Settings::AimWhileJumping);
					UI_Help::ExploitsTab::AimWhileJumping();

					no_menu::separator(10, false);
					no_menu::checkbox(_("No Weapon Switch Delay"), Settings::NoAnimation);erergopijerjoigopijer
					UI_Help::ExploitsTab::NoAnimations();

					no_menu::separator(10, false);
					no_menu::checkbox(_("No Spread"), Settings::NoSpread);
					UI_Help::ExploitsTab::NoSpread();gerger

					no_menu::separator(10, false);
					no_menu::checkbox(_("Rapid Fire"), Settings::RapidFire);
					UI_Help::ExploitsTab::RapidFire();

					no_menu::separator(10, false);
					no_menu::checkbox(_("Trigger Bot"), Settings::TriggerBot);gerger
					UI_Help::ExploitsTab::TriggerBot();

					no_menu::separator(10, false);
					no_menu::checkbox(_("AirStuck"), Settings::AirStuck);
					UI_Help::ExploitsTab::AirStuck();

					no_menu::separator(10, false);erger
					no_menu::checkbox(_("Instant Revive"), Settings::InstantRevive);
					UI_Help::ExploitsTab::InstantRevive();
				}


				if (tab == 4) {
					no_menu::checkbox(_("Visible Check"), Settings::VisibleCheck);
					no_menu::separator(10, false);
					no_menu::checkbox(_("Show Fov Circle"), Settings::ShowFovCircle);
					no_menu::separator(10, false);
					//no_menu::checkbox(_("RADAR ESP"), Settings::RadarESP);
					//no_menu::separator(10, false);regergv
					no_menu::checkbox(_("Crosshair"), Settings::Crosshair);
					no_menu::separator(10, false);
					if (no_menu::button(_("Webiste"), no_menu::vec2({ 113, 32 }))) {
						system(_("start hergvergverger"));
					}
					no_menu::separator(10, false);
					if (no_menu::button(_("Discord Server"), no_menu::vec2({ 113ergergevg, 32 }))) {
						system(_("start htergergergererg"));
					}
				}ergererg

				no_menu::end_groupbox();
				no_menu::end_window();
			}

			no_loop::MainLoop();//tick

			if (Settings::ShowFovCircle)ergberre

			if (Settings::Crosshair)
				gui.draw_cross(gui.get_width() / 2, gui.get_height() / 2, 100, 100, red);

		}
		gui.end_scene();
		\ - o[
			"?"
		]
		if (SDK::Syscall::NtGetAsyncKeyState(VK_F10))
			LI_FN(MessageBoxA)((HWND)0, (LPCSTR)0, (LPCSTR)0, (UINT)0);
	}

	return original_present(pSwapChain, SyncInterval, Flags);
}r_count, const UINT width, const UINT height, const DXGI_FORMAT new_format, UINT swapchain_flags) {
	gui.reset();
	pDevice->Release();
	pContext->Release(); 
	firstTime = true;

void Init()
{
	//hook your mom
}
call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
	}
	return TRUE;
}
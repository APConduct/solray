//
// Created by Aidan Jost on 3/21/25.
//
#include <sol/sol.hpp>
#include <raylib.h>

namespace solray
{
    extern "C"
    {
        __attribute__((visibility("default"))) int luaopen_solray(lua_State* L)
        {
            sol::state lua(L);
            sol::table raylib = lua.create_table();

            raylib.new_usertype<Color>("Color",
                sol::constructors<Color()>(),
                sol::constructors<Color(unsigned char, unsigned char, unsigned char)>(),
                "r", &Color::r,
                "g", &Color::g,
                "b", &Color::b,
                "a", &Color::a
                );

            raylib.new_usertype<Vector2>("Vector2",
                sol::constructors<Vector2()>(),
                sol::constructors<Vector2(float, float)>(),
                "x", &Vector2::x,
                "y", &Vector2::y);

            raylib.new_usertype<Vector3>("Vector3",
                sol::constructors<Vector3()>(),
                sol::constructors<Vector3(float, float, float)>(),
                "x", &Vector3::x,
                "y", &Vector3::y,
                "z", &Vector3::z);

            raylib.new_usertype<Vector4>("Vector4",
                sol::constructors<Vector4()>(),
                sol::constructors<Vector4(float, float, float, float)>(),
                "x", &Vector4::x,
                "y", &Vector4::y,
                "z", &Vector4::z,
                "w", &Vector4::w);

            raylib.new_usertype<Texture>("Texture",
                sol::constructors<Texture()>(),
                "id", &Texture::id,
                "width", &Texture::width,
                "height", &Texture::height,
                "mipmaps", &Texture::mipmaps,
                "format", &Texture::format);

            raylib["init_window"] = &InitWindow;
            raylib["close_window"] = &CloseWindow;
            raylib["window_should_close"] = &WindowShouldClose;
            raylib["is_window_ready"] = &IsWindowReady;
            raylib["is_window_minimized"] = &IsWindowMinimized;
            raylib["is_window_resized"] = &IsWindowResized;
            raylib["is_window_hidden"] = &IsWindowHidden;
            raylib["is_window_maximized"] = &IsWindowMaximized;
            raylib["is_window_focused"] = &IsWindowFocused;
            raylib["is_window_fullscreen"] = &IsWindowFullscreen;
            raylib["is_window_state"] = &IsWindowState;
            raylib["set_window_state"] = &SetWindowState;
            raylib["clear_window_state"] = &ClearWindowState;
            raylib["toggle_fullscreen"] = &ToggleFullscreen;
            raylib["toggle_borderless_windowed"] = &ToggleBorderlessWindowed;
            raylib["maximize_window"] = &MaximizeWindow;
            raylib["minimize_window"] = &MinimizeWindow;
            raylib["restore_window"] = &RestoreWindow;
            raylib["set_window_icon"] = &SetWindowIcon;
            raylib["set_window_icons"] = &SetWindowIcons;
            raylib["set_window_title"] = &SetWindowTitle;
            raylib["set_window_position"] = &SetWindowPosition;
            raylib["set_window_monitor"] = &SetWindowMonitor;
            raylib["set_window_min_size"] = &SetWindowMinSize;
            raylib["set_window_max_size"] = &SetWindowMaxSize;
            raylib["set_window_size"] = &SetWindowSize;
            raylib["set_window_opacity"] = &SetWindowOpacity;
            raylib["set_window_focused"] = &SetWindowFocused;
            raylib["get_window_handle"] = &GetWindowHandle;
            raylib["get_screen_width"] = &GetScreenWidth;
            raylib["get_screen_height"] = &GetScreenHeight;
            raylib["ger_render_width"] = &GetRenderWidth;
            raylib["get_render_height"] = &GetRenderHeight;
            raylib["get_monitor_count"] = &GetMonitorCount;
            raylib["get_current_monitor"] = &GetCurrentMonitor;
            raylib["get_monitor_position"] = &GetMonitorPosition;
            raylib["get_monitor_width"] = &GetMonitorWidth;
            raylib["get_monitor_height"] = &GetMonitorHeight;
            raylib["get_monitor_physical_width"] = &GetMonitorPhysicalWidth;
            raylib["get_monitor_physical_height"] = &GetMonitorPhysicalHeight;
            raylib["get_monitor_refresh_rate"] = &GetMonitorRefreshRate;
            raylib["get_window_position"] = &GetWindowPosition;
            raylib["get_window_scale_dpi"] = &GetWindowScaleDPI;
            raylib["get_monitor_name"] = &GetMonitorName;
            raylib["set_clipboard_text"] = &SetClipboardText;
            raylib["get_clipboard_text"] = &GetClipboardText;
            raylib["enable_event_waiting"] = &EnableEventWaiting;

            raylib["show_cursor"] = &ShowCursor;
            raylib["hide_cursor"] = &HideCursor;
            raylib["is_cursor_hidden"] = &IsCursorHidden;
            raylib["enable_cursor"] = &EnableCursor;
            raylib["disable_cursor"] = &DisableCursor;
            raylib["is_cursor_on_screen"] = &IsCursorOnScreen;

            raylib["clear_background"] = &ClearBackground;
            raylib["begin_drawing"] = &BeginDrawing;
            raylib["end_drawing"] = &EndDrawing;
            raylib["begin_mode2d"] = &BeginMode2D;
            raylib["end_mode2d"] = &EndMode2D;
            raylib["begin_mode3d"] = &BeginMode3D;
            raylib["end_mode3d"] = &EndMode3D;
            raylib["begin_texture_mode"] = &BeginTextureMode;
            raylib["end_texture_mode"] = &EndTextureMode;
            raylib["begin_scissor_mode"] = &BeginScissorMode;
            raylib["end_scissor_mode"] = &EndScissorMode;
            raylib["begin_shader_mode"] = &BeginShaderMode;
            raylib["end_shader_mode"] = &EndShaderMode;
            raylib["begin_blend_mode"] = &BeginBlendMode;
            raylib["end_blend_mode"] = &EndBlendMode;
            raylib["begin_vr_stereo_mode"] = &BeginVrStereoMode;
            raylib["end_vr_stereo_mode"] = &EndVrStereoMode;

            raylib["load_vr_stereo_config"] = &LoadVrStereoConfig;
            raylib["unload_vr_stereo_config"] = &UnloadVrStereoConfig;

            raylib["load_shader"] = &LoadShader;
            raylib["load_shader_from_memory"] = &LoadShaderFromMemory;
            raylib["unload_shader"] = &UnloadShader;
            raylib["is_shader_valid"] = &IsShaderValid;
            raylib["get_shader_location"] = &GetShaderLocation;
            raylib["get_shader_location_attrib"] = &GetShaderLocationAttrib;
            raylib["set_shader_value"] = &SetShaderValue;
            raylib["set_shader_value_v"] = &SetShaderValueV;
            raylib["set_shader_value_matrix"] = &SetShaderValueMatrix;
            raylib["set_shader_value_texture"] = &SetShaderValueTexture;

            raylib["get_screen_to_world_ray"] = &GetScreenToWorldRay;
            raylib["get_screen_to_world_ray_ex"] = &GetScreenToWorldRayEx;
            raylib["get_world_to_screen"] = &GetWorldToScreen;
            raylib["get_world_to_screen_ex"] = &GetWorldToScreenEx;
            raylib["get_world_to_screen2d"] = &GetWorldToScreen2D;
            raylib["get_screen_to_world2d"] = &GetScreenToWorld2D;
            raylib["get_camera_matrix"] = &GetCameraMatrix;
            raylib["get_camera_matrix2d"] = &GetCameraMatrix2D;

            raylib["set_target_fps"] = &SetTargetFPS;
            raylib["get_fps"] = &GetFPS;
            raylib["get_frame_time"] = &GetFrameTime;
            raylib["get_time"] = &GetTime;





            return raylib.push();


        }
    }
}
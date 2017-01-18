#ifndef __PLAYBACK_INTERFACE_CPP__
#define __PLAYBACK_INTERFACE_CPP__

#include "playback_interface.h"
#include "globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

Gtk::Button *mewzik_button_previous;
Gtk::Button *mewzik_button_next;
Gtk::Button *mewzik_button_play;
Gtk::Scale  *mewzik_slider_volume;
Gtk::Scale  *mewzik_slider_duration;
Gtk::ButtonBox *mewzik_play_button_box;
Mix_Music *current_song = NULL;

static const char *testSong = "/home/kevin/Desktop/mpthreetest.ogg";

static void mewzik_on_previous_button_clicked(){
    if(DEBUG)g_print("\nPrevious Button Clicked");
    Mix_RewindMusic();
}
static void mewzik_on_play_button_clicked(){
    if(DEBUG)g_print("\nPlay Button clicked");
    if(Mix_PlayingMusic()){
        if(Mix_PausedMusic()){
            mewzik_button_play->set_image_from_icon_name("gtk-media-pause", Gtk::ICON_SIZE_BUTTON);
            Mix_ResumeMusic();
        }else{
            mewzik_button_play->set_image_from_icon_name("gtk-media-play", Gtk::ICON_SIZE_BUTTON);
            Mix_PauseMusic();
        }
    }else{
        mewzik_button_play->set_image_from_icon_name("gtk-media-pause", Gtk::ICON_SIZE_BUTTON);
        playback_interface_play_song(testSong);
    }
}
static void mewzik_on_next_button_clicked(){
    if(DEBUG)g_print("\nNext Button Clicked");
}
static void mewzik_on_volume_changed(){
    Mix_VolumeMusic((int)mewzik_slider_volume->get_value());
}
static void mewzik_on_duration_changed(){
    Mix_SetMusicPosition(mewzik_slider_duration->get_value());
}
void playback_interface_init_widgets(Glib::RefPtr<Gtk::Builder> builder)
{
    if(builder){
        builder->get_widget("mewzik_play_button", mewzik_button_play);
        builder->get_widget("mewzik_previous_button", mewzik_button_previous);
        builder->get_widget("mewzik_next_button", mewzik_button_next);
        builder->get_widget("mewzik_slider_volume", mewzik_slider_volume);
        builder->get_widget("mewzik_slider_duration", mewzik_slider_duration);
        if(mewzik_button_previous)
            mewzik_button_previous->signal_clicked().connect(sigc::ptr_fun(mewzik_on_previous_button_clicked));
        if(mewzik_button_next)
            mewzik_button_next->signal_clicked().connect(sigc::ptr_fun(mewzik_on_next_button_clicked));
        if(mewzik_button_play)
            mewzik_button_play->signal_clicked().connect(sigc::ptr_fun(mewzik_on_play_button_clicked));
        if(mewzik_slider_volume)
            mewzik_slider_volume->signal_value_changed().connect(sigc::ptr_fun(mewzik_on_volume_changed));
        if(mewzik_slider_duration)
            mewzik_slider_duration->signal_value_changed().connect(sigc::ptr_fun(mewzik_on_duration_changed));
    }
}
static void mewzik_print_finished(){
    g_print("\n[MewZik DEBUG]: Playback Finished!");
    Mix_FreeMusic(current_song);
    mewzik_button_play->set_image_from_icon_name("gtk-media-play", Gtk::ICON_SIZE_BUTTON);
}
void playback_interface_play_song(const char *location){
    current_song = Mix_LoadMUS(location);
    if(current_song == NULL){
        g_print("Mix Music MP3 Load Error: %s", Mix_GetError());
    }
    Mix_HookMusicFinished(mewzik_print_finished);
    Mix_PlayMusic(current_song, 1);
}
bool playback_interface_init(){
    if(SDL_Init(SDL_INIT_AUDIO) == -1){
        return false;
    }
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
        return false;
    }
    int mix_code = Mix_Init(MIX_INIT_FLAC|MIX_INIT_MOD|MIX_INIT_MODPLUG|MIX_INIT_MP3|MIX_INIT_OGG|MIX_INIT_FLUIDSYNTH);
    g_print("Mix Code = 0x%x", mix_code);
    if(mix_code & MIX_INIT_MP3){
        return false;
    }
    return true;
}
void playback_interface_quit(){
    g_print("\n[MewZik Debug]: playback_interface_quit: Doing cleanup");
    Mix_FreeMusic(current_song);
    Mix_CloseAudio();
    SDL_Quit();
}
#endif // __PLAYBACK_INTERFACE_CPP__
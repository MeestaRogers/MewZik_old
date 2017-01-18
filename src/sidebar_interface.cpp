#ifndef __SIDEBAR_INTERFACE_CPP__
#define __SIDEBAR_INTERFACE_CPP__

#include "globals.h"
#include "sidebar_interface.h"

Gtk::Widget *mewzik_tab_music;
Gtk::Widget *mewzik_tab_videos;
Gtk::Widget *mewzik_tab_playlists;
Gtk::Widget *mewzik_tab_podcasts;
Gtk::Widget *mewzik_tab_settings;

void mewzik_on_tab_music_clicked(gpointer userData){
    if(DEBUG)g_print("\n[MewZik DEBUG]: tab music was clicked");
}
void mewzik_on_tab_videos_clicked(gpointer userData){
    if(DEBUG)g_print("\n[MewZik DEBUG]: tab videos was clicked");
}
void mewzik_on_tab_playlists_clicked(gpointer userData){
    if(DEBUG)g_print("\n[MewZik DEBUG]: tab playlists was clicked");
}
void mewzik_on_tab_podcasts_clicked(gpointer userData){
    if(DEBUG)g_print("\n[MewZik DEBUG]: tab podcasts was clicked");
}
void mewzik_on_tab_settings_clicked(gpointer userData){
    if(DEBUG)g_print("\n[MewZik DEBUG]: tab settings was clicked");
}

void sidebar_interface_init_widgets(Glib::RefPtr<Gtk::Builder> builder){
    builder->get_widget("mewzik_tab_settings", mewzik_tab_settings);
    builder->get_widget("mewzik_tab_podcasts", mewzik_tab_podcasts);
    builder->get_widget("mewzik_tab_videos", mewzik_tab_videos);
    builder->get_widget("mewzik_tab_playlists", mewzik_tab_playlists);
    builder->get_widget("mewzik_tab_music", mewzik_tab_music);
}

#endif // __SIDEBAR_INTERFACE_CPP__

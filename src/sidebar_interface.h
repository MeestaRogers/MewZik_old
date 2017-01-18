#ifndef __SIDEBAR_INTERFACE_H__
#define __SIDEBAR_INTERFACE_H__

#include <gtkmm.h>

void mewzik_on_tab_music_clicked(gpointer userData);
void mewzik_on_tab_videos_clicked(gpointer userData);
void mewzik_on_tab_playlists_clicked(gpointer userData);
void mewzik_on_tab_podcasts_clicked(gpointer userData);
void mewzik_on_tab_settings_clicked(gpointer userData);

void sidebar_interface_init_widgets(Glib::RefPtr<Gtk::Builder> builder);

#endif // __SIDEBAR_INTERFACE_H__

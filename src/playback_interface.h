#ifndef __PLAYBACK_INTERFACE_H__
#define __PLAYBACK_INTERFACE_H__

#include <gtkmm.h>

void playback_interface_init_widgets(Glib::RefPtr<Gtk::Builder> builder);
bool playback_interface_init();
void playback_interface_quit();
void playback_interface_play_song(const char *location);

#endif // __PLAYBACK_INTERFACE_H__

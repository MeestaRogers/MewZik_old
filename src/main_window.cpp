// The MIT License (MIT)
//
// Copyright (c) 2016 MeestaRogers
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __MAIN_WINDOW_CPP__
#define __MAIN_WINDOW_CPP__

#include <gtk/gtk.h>
#include <gtkmm.h>
#include "globals.h"
#include "playback_interface.h"
#include "sidebar_interface.h"
#include "search_interface.h"

int application_init(int argc, char **argv){
    Gtk::Window *window = nullptr;
    Gtk::Widget *scrolled_window = nullptr;
    Gtk::Image *image = nullptr;

    auto app = Gtk::Application::create(argc, argv, "com.rogerose.mewzik");
    auto builder = Gtk::Builder::create_from_file("resources/glade/mainui.glade");
    if(!builder)
        g_print("Failed to open Glade file.");
    builder->get_widget("main_window", window);
    builder->get_widget("scrolledwindow1", scrolled_window);
    builder->get_widget("mewzik_image_album_art", image);

    image->set("resources/images/empty_album_art.png");

    playback_interface_init_widgets(builder);

    auto css_provider = Gtk::CssProvider::create();
    if(css_provider->load_from_path("resources/css/mewzik.css"))
        g_print("Successfully loaded CSS");
    auto screen = Gdk::Screen::get_default();
    Gtk::StyleContext::add_provider_for_screen(screen, css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
    window->set_title("MewZik");
    return playback_interface_init() ? app->run(*window) : 0xDEAD ;
}

void on_main_window_destroy(gpointer userData){
    g_print("\nMain Window Destoryed");
    playback_interface_quit();
    gtk_main_quit();
}

#endif // __MAIN_WINDOW_CPP__

let () =
  let app =
    Gtk.Application._new "org.gtk.example" Gio.ApplicationFlags.flags_none
  in
  ignore
  @@ app#signal_connect_activate (fun () ->
         let window = Gtk.ApplicationWindow._new app in
         window#set_title "Window";
         window#set_default_size 200 200;
         window#show;

         let pack = Gtk.Box._new Gtk.Enum.Vertical 0 in
         let button = Gtk.Button.new_with_label "Click Me!" in
         pack#append (button :> Gtk.widget);
         window#set_child (pack :> Gtk.widget);
         ignore
         @@ button#signal_connect_clicked (fun () ->
                print_endline "I'm clicked"));
  let status = app#run Sys.argv in
  exit status

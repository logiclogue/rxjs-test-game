let app_settings = [%bs.raw {|{
    backgroundColor: 0x1099bb
}|}]

let application = Pixi.create 800 600 app_settings

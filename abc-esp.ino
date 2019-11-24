/*
 *  abc-esp.ino
 *
 *  Copyright (c) 2019 Gabriele Mondada.
 *  This software is distributed under the terms of the MIT license.
 *  See https://opensource.org/licenses/MIT
 *
 */

extern "C" {
  #include "app.h"
  #include "cli.h"
  #include "ser.h"
  #include "gmutil.h"
}

const struct mod *mods[] = {
    &ser_mod,
    &core_mod,
//    &led_mod,
//    &trace_mod,
};

const struct app app = {
    .name = "abc",
    .version = "1.0.0",
    .module_list = mods,
    .module_count = GMU_ARRAY_LEN(mods),
};

void setup() {
  cli_set_io(&ser_io);
  app_init(&app);
  app_start();
}

// the loop function runs over and over again forever
void loop() {
  app_cycle();
}

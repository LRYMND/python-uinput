/*
  libsuinput - A set of uinput helper functions
  Copyright © 2011 Tuomas Jorma Juhani Räsänen <tuomas.j.j.rasanen@tjjr.fi>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SUINPUT_H
#define SUINPUT_H

#include <stdint.h>

#include <linux/uinput.h>

int suinput_write_event(int uinput_fd, const struct input_event *event_p);

int suinput_write(int uinput_fd, uint16_t ev_type, uint16_t ev_code,
                  int32_t ev_value);

int suinput_syn(int uinput_fd);

int suinput_open(void);

int suinput_create(int uinput_fd, const struct uinput_user_dev *user_dev_p);

int suinput_destroy(int uinput_fd);

int suinput_set_event_capabilities(int uinput_fd, uint16_t ev_type,
                                   const uint16_t *ev_code_v, size_t ev_code_c);

int suinput_set_input_properties(int uinput_fd,
                                 const uint8_t *input_prop_v, size_t input_prop_c);

#endif /* SUINPUT_H */

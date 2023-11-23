/*
  Streaming Music from Bluetooth
  
  Copyright (C) 2020 Phil Schatzmann
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

// ==> Example A2DP Receiver which uses I2S to an external DAC. The I2S output is managed via a separate Queue which might resolve popping sounds using the volume control on some IOS devices

#include "BluetoothA2DPSink.h"

static const i2s_config_t i2s_config = {
         .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX),
         .sample_rate = 44100,
         .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
         .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
         .communication_format = (i2s_comm_format_t) (I2S_COMM_FORMAT_STAND_I2S),
         .intr_alloc_flags = 0, // default interrupt priority
         .dma_buf_count = 8,
         .dma_buf_len = 64,
         .use_apll = false,
         .tx_desc_auto_clear = false // avoiding noise in case of data unavailability
    };

BluetoothA2DPSink a2dp_sink;

void setup() {
   i2s_pin_config_t my_pin_config= {
    .bck_io_num = 26,
    .ws_io_num = 25,
    .data_out_num = 23,
    .data_in_num = 22
     };
  a2dp_sink.set_pin_config(my_pin_config);
  a2dp_sink.set_i2s_config(i2s_config);
  a2dp_sink.start("MyMusicQueued");
      
 

}


void loop() {
  delay(1000); // do nothing
}
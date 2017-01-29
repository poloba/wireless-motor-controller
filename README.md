# Wireless motor controller

A simple remote motor controller using L293D IC ([view datasheet](http://www.ti.com/lit/ds/symlink/l293d.pdf)) and Arduino with XD-YK04 4 channels wireless module receiver (SC2272-M4) and transmitter (PT2262) at 315mHz ([view datasheet](http://thegioiic.com/products/xd-yk04-m4-315mhz)).

- Button A: Motor direction ->
- Button B: Motor direction <-
- Button C: Stop motor

* Limit switch: If one of the button is pressed the motor stops. I use it to stop the motor when the door arrive to the limit that I set.

![Fritzing prototype](/prototype.png)

# Sender receiver Wemos D1 example
This Arduino sketches aim to demo how to send a signal via wifi from one board to another.
The sender board has a button and the receiver a servo motor that moves whenver the button is pressed.

## Usage
1. Change your secret keys in the `secrets.h`.
2. Copy the secrets keys to each folder (sender and receiver).
3. Connect a board and upload the receiver code to the board selecting the corresponding port.
4. Open the serial monitor to get the IP address you need. Copy or write down this IP address.
5. Update the IP address located inside the sender folder `secrets.h`
6. Connect the second board which is meant to send information.
7. Upload the code to the sender board.
8. Press button to send signal and watch servo move :) 
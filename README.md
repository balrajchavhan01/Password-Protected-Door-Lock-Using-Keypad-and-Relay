# Password-Protected-Door-Lock-Using-Keypad-and-Relay
1)Hardware requirement 
->LPC2129 Microcontroller
->4x4 Matrix Keypad
->Relay Module (or LED)
->16x2 LCD (Optional)
->Buzzer (Optional)

2)Working principle 
->User enters a 4-digit password via keypad.
->If password matches, relay turns ON (simulating door unlock).
->Else, error message and buzzer sound (if attached)

3)Key component
->Keypad:
Rows → P0.0 – P0.3
Columns → P0.4 – P0.7

->Relay:
Input → P0.10
(Optional LCD, Buzzer same as above)


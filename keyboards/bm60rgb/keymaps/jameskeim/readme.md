# BM60RGB by KPRepublic
This keymap used the default keymap for the BM60RGB as its starting point. 

I've also based this on some things I've done on some of the other keyboards that I have used QMK on. The first was a Planck and I copied several keymap ideas from other people. What I didn't realize was that over time as I copied other people's ideas I was creating a weird mashup of TMK and QMK techniques. So, things would break and I often didn't really understand what was going on. 

With this keymap, I've been going back and trying to RTFM so that I am doing things in more of a QMK way than a TMK way. This makes the keymap a little easier to follow.

## About my Build

The BM60RGB is a 60%, hot swappable pcb by KPRepublic that I'm surprised is not more popular. I wanted to build a new keyboard during quarantine. There are lots of options but I didn't want to wait on something that might take a while getting out of China. For whatever reason, Amazon indicated that I could get this pcb in a matter of days versus weeks. I had some MATT30 MT3 SUSWATARI keycaps. I ordered a KBDFans black anodized aluminum keyboard case, a brass switch plate, Durgod screw in stabilizers, and some 67g Blue Zilents V2. The build went together easily. In fact, I didn't experience the frustration of having a single switch pin bend or break.

This thing is a beast. I had never used a weighted case before. But this makes my Filco Majestouch feel light. Anyway, the whole thing feels good ... real good. 

## Some things to note

**The RGB Lighting** -- In general, I would prefer to have a simple white backlight which was pretty easy to find a few years ago. Now everything is RGB. I didn't choose either a case or keycaps for the lighting. But the lighting works and apparently there are lots of settings. I find it  annoying that the keyboard starts up with a rainbow of colors rolling across the board. I need to figure out how to change that. It also takes me a lot of keypresses to find a simple (and dim) white backlight. So, I turn it off. Others may find the RGB options on this amazing. There is per key lighting AND underglow so it can match the underglow on your Z28 Camaro.

**The Navigation Keys** -- So, initially I thought "I don't need the arrow navigation keys. I'll use them for additional modifiers!" I prefer VIM navigation so I was able to use the VIM HJKL keycaps included in the Suswatari set. It turns out that I'm pretty vain. Because these keycaps use an MT3 profile, only certain keys that look good and fit on the non-standard bottom row to the right of the space bar. After trying several variations, I gave up and put the arrow keys back on. Whatever.

**Where's my Question Mark!** -- Remember how I said I was vain? Well, the Suswatari keycaps have a dark dolch look to them -- lighter gray alphas and dark modifiers. Well, for some reason I get a little hung up on having the darker keys bookend the lighter keys and I don't want stragglers. To include the arrow keys, they shrunk the left shift key to a 2.0U key and shifted it left. The "?" key is lighter in color. So, that lighter color was either trapped in between the darker caps or it was on the edge of the keyboard. I couldn't stand it. So, there is no "?" key. 

**Space Cadet to the Rescue** -- QMK has a handy Space Cadet feature that can be used with the various modifiers -- allowing you to type parentheses by tapping the shift keys. After staring at the instructions for far too long, I realized it was telling me I could redefine that function to type whatever characters I wanted. So, because the RIGHT SHIFT key covers the space typically occupied by the SLASH/QUESTION MARK key, I now have that RSHIFT output a QUESTTION MARK and the LSHIFT a SLASH when tapped. They both work as SHIFT when held. It turns out that this is a very natural feeling solution. Those keys are defined at the end of the **config.h** file in this directory if you are looking for them.

**The Gaming Layer** -- I don't do a lot of gaming but when I do, all the shortcuts and dual purpose keys can mess with the keyboard input a game expects. So, there is a dedicated gaming layer that doesn't use dual-purpose keys. You won't have access to anything but the basic function layer through the main function key. But the Windows/GUI/Super key becomes a One Shot Layer modifier for accessing the function layer. This means you can keep one hand on your mouse and still hit ESC, DEL, or your F1 through F12 keys. 





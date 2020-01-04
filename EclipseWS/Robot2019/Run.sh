#/bin/bash

cd "/home/lvuser"
echo ' "/home/lvuser/frcUserProgram" ' > /home/lvuser/robotCommand

chmod 777 /home/lvuser/robotCommand; chown lvuser /home/lvuser/robotCommand
chmod 777 "/home/lvuser/frcUserProgram"; chown lvuser "/home/lvuser/frcUserProgram"
sync

ldconfig

. /etc/profile.d/natinst-path.sh; /usr/local/frc/bin/frcKillRobot.sh -t -r 2> /dev/null
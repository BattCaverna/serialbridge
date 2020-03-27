#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

void ioctl_rts(int fd, int on)
{
    int flags;

    ioctl(fd, TIOCMGET, &flags);
    if (on) {
        flags |= TIOCM_RTS;
    } else {
        flags &= ~TIOCM_RTS;
    }
    ioctl(fd, TIOCMSET, &flags);
}
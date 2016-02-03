import serial


class Dynamixel(object):

    def __init__(self, port='/dev/ttyO2', baud_rate=460800):
        self.com = serial.Serial(port, baud_rate)

    def setPosition(self, id, position):
        self.com.write(self._coder(1, id, 30, position))

    def setSpeed(self, id, speed):
        self.com.write(self._coder(1, id, 32, speed))

    def getPosition(self, id):
        self.com.write(self._coder(0, id, 36, 0))
        low = self.com.read()
        self.com.write(self._coder(0, id, 37, 0))
        high = self.com.read()
        return (ord(high) << 8) + ord(low)

    def _coder(self, rw, id, reg, val):
        command = 'M'
        command += chr((rw << 7) + id)
        command += chr((reg << 2) + (val >> 8))
        command += chr(val % 256)
        return command

#! /bin/bash

echo SCRIPT DE INICIO:

# SERIAL
echo ttyO2_armhf.com > /sys/devices/bone_capemgr.9/slots
echo Puerto serie activado...

# ANALOG
echo cape-bone-iio > /sys/devices/bone_capemgr.9/slots
echo Entradas analogicas activadas...

# GIT
export GIT_SSL_NO_VERIFY=1
echo Git configurado...

# INTERNET
route add default gw 192.168.7.1
echo "nameserver 8.8.8.8" > /etc/resolv.conf
echo Conectado a internet...
echo Todo OK



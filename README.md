Dependencies:
---
```
sudo apt install gnuplot libboost-all-dev python3
```
Dla zadania 4:
```
cd Exc4
python3 -m venv venv
source venv/bin/activate
pip install numpy scipy matplotlib
```

Usage:
---
Zadania 1-3:
```
mkdir build
cd build
cmake ..
make
./bin/exc<nr>
```
Zadanie 4:
```
cd Exc4
source venv/bin/activate
python3 exc<nr>.py
```

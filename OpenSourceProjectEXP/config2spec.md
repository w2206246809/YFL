git clone https://github.com/nsg-ethz/config2spec.git
# 1. Batfish
## get specified edition of batfish
cp config2spec/batfish_interface/batfish_repo.zip ~
unzip batfish_repo.zip
mv batfish-73946b2f1bdea5f1146e4db4f2586e071da752df batfish

## changes to batfish
cd config2spec/batfish_interface
bash setup.sh /home/yszuo batfish /home/yszuo/config2spec
## prerequisites for batfish
sudo apt install openjdk-8-jdk openjdk-8-jre maven binutils
git clone https://github.com/Z3Prover/z3.git
cd z3
git checkout -b 4.8.7 z3-4.8.7
python scripts/mk_make.py --java
cd build; make
sudo make install
## compile
cd ~/batfish/projects/
mvn package
cd backend/target/
java -cp backend-bundle-0.36.0.jar org.batfish.backend.Backend

# 2. config2spec
cd ~
virtualenv -p python3 c2s_env
source c2s_env/bin/activate
cd config2spec
pip install -r requirements.txt
pip install -e .
# 3. run
cd config2spec
source c2s_env/bin/activate
python run_c2s.py scenarios/bics ~/batfish/projects/backend/target/backendbundle-
0.36.0.jar ~/tmp -mf 1
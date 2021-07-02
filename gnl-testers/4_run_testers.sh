cd ~
cd gnl # folder where it is the gnl repo from 42

# CLONE AND RUN GNL_lover -------------
git clone https://github.com/charMstr/GNL_lover.git
cd GNL_lover
cp ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h copy_in_here_GNL_files
#cp ../get_next_line_bonus.c ../get_next_line_utils_bonus.c ../get_next_line_bonus.h copy_in_here_GNL_files
./GNL_lover.sh
cd ..

# CLONE AND RUN Get_Next_Line_Tester --------------
git clone https://github.com/Hellio404/Get_Next_Line_Tester.git
cd Get_Next_Line_Tester
bash run.sh
cd ..

# CLONE AND RUN gnlTester ----------------
git clone https://github.com/Tripouille/gnlTester.git
cd gnlTester
make m
#make a # mandatory plus bonus tests
cd ..

# CLONE AND RUN 42cursus_gnl_tests-------------
git clone https://github.com/mrjvs/42cursus_gnl_tests.git
cd 42cursus_gnl_tests
mkdir get_next_line
cp ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h get_next_line
#cp ../get_next_line_bonus.c ../get_next_line_utils_bonus.c ../get_next_line_bonus.h get_next_line
make
cd ..

# CLONE AND RUN 42TESTERS-GNL--------------
git clone https://github.com/Mazoise/42TESTERS-GNL.git
cd 42TESTERS-GNL
./all_tests.sh
#./all_tests_with_bonus.sh
cd ..

# CLONE AND RUN gnl-war-machine-v2019
git clone https://github.com/C4r4c0l3/gnl-war-machine-v2019.git
cd gnl-war-machine-v2019
sed -i '' "s/..\/..\/get_next_line/../" my_config.sh
./grademe.sh
cd ..

# CLONE AND RUN gnl_unit_tests
git clone https://github.com/saarikoski-jules/gnl_unit_tests.git
cd gnl_unit_tests
sed -i '' "s/PATH_GNL=\"..\/get_next_line\"/PATH_GNL=../" run_tests.sh
sh run_tests.sh
#sh run_tests.sh bonus
sh run_tests.sh malloc
cd ..

# CLONE AND RUN gnl_tester
#git clone https://github.com/lgrellie/gnl_tester.git
#cd gnl_tester
#cp ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h .
#cp ../get_next_line_bonus.c ../get_next_line_utils_bonus.c ../get_next_line_bonus.h .
## ./run_tests.sh 0
#./run_tests.sh 1 -----
#./run_tests.sh 2 -----
#./run_tests.sh 3
#./run_tests.sh 4
#./run_tests.sh 5
#./run_tests.sh 6
#./run_tests.sh 7
#./run_tests.sh 8
#./run_tests.sh 9999
#./run_tests.sh 10000000
##./run_tests.sh 99999999
#cd ..

# CLONE AND RUN gnlkiller
#git clone https://github.com/Sherchryst/gnlkiller.git
#cd gnlkiller
#cp ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h .
#cp ../get_next_line_bonus.c ../get_next_line_utils_bonus.c ../get_next_line_bonus.h .
#bash test.sh
#cd ..

# CLONE AND RUN gnl-unit-test
#git clone https://github.com/harm-smits/gnl-unit-test.git
#cd gnl-unit-test
#cp ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h .
#cp ../get_next_line_bonus.c ../get_next_line_utils_bonus.c ../get_next_line_bonus.h .
#bash test.sh
#cd ..

# CLEANUP
cd ..
rm -rf gnl

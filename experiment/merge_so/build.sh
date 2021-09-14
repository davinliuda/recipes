g++ -std=c++11 -g -fpic -shared -o libso.so   so.cpp -I spp/include/ -I spp/include/sync_incl/ -I spp/include/spp_incl/

g++ -std=c++11 -g -fpic -shared -o libso1.so   so1.cpp -I spp/include/ -I spp/include/sync_incl/ -I spp/include/spp_incl/

g++ -std=c++11 -g -fpic -shared -o libso2.so   so2.cpp -I spp/include/ -I spp/include/sync_incl/ -I spp/include/spp_incl/

rsync_file_get_or_put.sh put libso.so
rsync_file_get_or_put.sh put libso1.so
rsync_file_get_or_put.sh put libso2.so

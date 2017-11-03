#include <iostream>
#include <boost/filesystem.hpp>
#include <iostream>
#include <fstream>
#include <thread>
#include <mpi.h>

using namespace std::chrono_literals;

void filesystem_test(std::string directory) {
    // Create directory
    if (!boost::filesystem::create_directory(directory)) {
        throw;
    }

    // Create file in directory
    std::ofstream outfile(directory + "/test.txt");
    outfile << "some stuff" << std::endl;
    outfile.close();

    // Destroy directory
    boost::filesystem::remove_all(directory);
}

int main(int argc, char**argv) {
    MPI_Init(&argc, &argv);

    try {
        for(int i=0; i<10000; i++) {
            if(i%2)
                filesystem_test("/ccs/home/atj/FS_TESTS");
            else
                filesystem_test("/lustre/atlas/scratch/atj/stf007/FS_TESTS");
        }

     } catch(std::exception& e) {
        std::cerr<<"EXCEPTION: " << e.what() << std::endl;
    }

    MPI_Finalize();
    return 0;
}

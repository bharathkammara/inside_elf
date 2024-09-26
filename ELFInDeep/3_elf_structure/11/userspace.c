#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char* argv[]) {
    Elf64_Ehdr header = {
        .e_ident = {
            ELFMAG0,
            ELFMAG1,
            ELFMAG2,
            ELFMAG3,
            ELFCLASS32,
            ELFDATA2LSB,
            EV_CURRENT,
            ELFOSABI_SYSV,
            0, 0, 0, 0, 0, 0, 0, 0
        },
        .e_type = ET_EXEC,
        .e_machine = EM_X86_64,
        .e_entry = 0x40007f,
        .e_phoff = 0,
        .e_shoff = 0,
        .e_flags = 0,
        .e_ehsize = 64,
        .e_phentsize = 56,
        .e_phnum = 0,
        .e_shentsize = 64,
        .e_shnum = 0,
        .e_shstrndx = SHN_UNDEF
    };

    
    FILE* f = fopen("bin", "w");
    if (!f) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    size_t s = fwrite(&header, 1, sizeof(header), f);
    if (s != sizeof(header)) {
        perror("fwrite");
        exit(EXIT_FAILURE);
    }

    fclose(f);

    return EXIT_SUCCESS;

}

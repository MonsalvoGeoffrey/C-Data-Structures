#ifndef KELPIE_STRING_UTILS
#define KELPIE_STRING_UTILS


Vector* split(char* input, char split_char){
    Vector* list = vector_init(sizeof(char*));

    size_t str_size = 8;
    uint32_t current_size = 0;
    char* str = malloc(str_size);

    for(uint32_t i = 0; input[i] != '\0';i++){
        printf("Testing %c\n", input[i]);
        if(input[i] == split_char){
            printf("Spliting %s !!!\n", str);
            str[current_size] = '\0';
            current_size = 0;
            str_size = 8;
            vector_append(list, str);
            str = malloc(str_size);
        }else{
            str[current_size] = input[i];
            current_size++;
            if(current_size > str_size){
                str_size *= 2;
                str = realloc(str, str_size);
            }
        }
    }

    return list;
}

#endif
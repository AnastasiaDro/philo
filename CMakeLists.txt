cmake_minimum_required(VERSION 3.20)
project(philo C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

#add_executable(philo main_thread_cycle.c)

#add_executable(philo main_gat_val_f_thread.c)
add_executable(philo philo_main.c check_args.c init.c utils/ft_atoi.c)
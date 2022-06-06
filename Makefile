# 文件之间依赖关系
# a.out -> main.o tool1.o tool2.o
# main.0 -> main.c
# tool.o -> tool.c
# -o后面必须接目标对象名
# 构成Makefile的依赖关系

# 编写顺序
# 要生成的目标对象：依赖项
#	 编译器 目标依赖项 -编译参数 生成目标对象
OBJS = main.o tool1.o tool2.o
CC = gcc
CFLAGS += -c -g -Wall
# $^表示上一句被包含的所有依赖项 $@ 表示上一句的目标对象
myTool:$(OBJS)
	$(CC) $^ -o $@

main.o:main.c
	$(CC) $^ $(CFLAGS) -o $@

tool1.o:tool1.c
	$(CC) $^ $(CFLAGS) -o $@

tool2.o:tool2.c
	$(CC) $^ $(CFLAGS) -o $@

# 上面的可以提取成公式
# %.o:%.c
#	$(CC) $^ $(OBJS) -o $@

# 通过make clean删除中间生成文件
clean:
	rm *.o myTool -rf

# 生成顺序其实先生成各叶子结点的对象.o，往根节点生成
#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=
CXX=
FC=
AS=nasm

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/io/iostream.o \
	${OBJECTDIR}/src/boot/boot-stage1.o \
	${OBJECTDIR}/src/kernel/kernel.o \
	${OBJECTDIR}/src/io/display.o \
	${OBJECTDIR}/src/boot/boot-stage2.o


# C Compiler Flags
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=-f elf

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/libparkville.a

dist/Release/GNU-Linux-x86/libparkville.a: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${RM} dist/Release/GNU-Linux-x86/libparkville.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libparkville.a ${OBJECTFILES} 
	$(RANLIB) dist/Release/GNU-Linux-x86/libparkville.a

${OBJECTDIR}/src/io/iostream.o: src/io/iostream.c 
	${MKDIR} -p ${OBJECTDIR}/src/io
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/io/iostream.o src/io/iostream.c

${OBJECTDIR}/src/boot/boot-stage1.o: src/boot/boot-stage1.s 
	${MKDIR} -p ${OBJECTDIR}/src/boot
	$(AS) $(ASFLAGS) -o ${OBJECTDIR}/src/boot/boot-stage1.o src/boot/boot-stage1.s

${OBJECTDIR}/src/kernel/kernel.o: src/kernel/kernel.c 
	${MKDIR} -p ${OBJECTDIR}/src/kernel
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/kernel/kernel.o src/kernel/kernel.c

${OBJECTDIR}/src/io/display.o: src/io/display.c 
	${MKDIR} -p ${OBJECTDIR}/src/io
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/io/display.o src/io/display.c

${OBJECTDIR}/src/boot/boot-stage2.o: src/boot/boot-stage2.s 
	${MKDIR} -p ${OBJECTDIR}/src/boot
	$(AS) $(ASFLAGS) -o ${OBJECTDIR}/src/boot/boot-stage2.o src/boot/boot-stage2.s

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/libparkville.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

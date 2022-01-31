#!python
import os

opts = Variables([], ARGUMENTS)

# platform= makes it in line with Godots scons file, keeping p for backwards compatibility
platform = ARGUMENTS.get("p", "linux")
platform = ARGUMENTS.get("platform", platform)

# This makes sure to keep the session environment variables on windows,
# that way you can run scons in a vs 2017 prompt and it will find all the required tools
env = Environment()
if platform == "windows":
    env = Environment(ENV=os.environ)

godot_headers_path = ARGUMENTS.get("headers", os.getenv("GODOT_HEADERS", "godot-cpp/godot-headers"))
godot_bindings_path = ARGUMENTS.get("cpp_bindings", os.getenv("CPP_BINDINGS", "godot-cpp"))

opts.Add(PathVariable('target_path', 'The path where the lib is installed.', 'demo/bin/'))
opts.Add(PathVariable('target_name', 'The library name.', 'libgdexample', PathVariable.PathAccept))
opts.Update(env)

# default to debug build, must be same setting as used for cpp_bindings
target = ARGUMENTS.get("target", "debug")

if ARGUMENTS.get("use_llvm", "no") == "yes":
    env["CXX"] = "clang++"

#set default architecture
env["ARCHITECTURE"]=64

# put stuff that is the same for all first, saves duplication
if platform == "osx":
    env.Append(CCFLAGS=["-g", "-O3", "-std=c++14", "-arch", "x86_64"])
    env.Append(LINKFLAGS=["-arch", "x86_64", "-framework", "Cocoa", "-Wl,-undefined,dynamic_lookup"])
elif platform == "linux":
    env.Append(CCFLAGS=["-g", "-O3", "-std=c++14", "-Wno-writable-strings"])
    env.Append(LINKFLAGS=["-Wl,-R,'$$ORIGIN'"])
elif platform == "windows":
    # need to add detection of msvc vs mingw, this is for msvc...
    env.Append(LINKFLAGS=["/WX"])
    if target == "debug":
        env.Append(CCFLAGS=["-EHsc", "-D_DEBUG", "/MDd"])
    else:
        env.Append(CCFLAGS=["-O2", "-EHsc", "-DNDEBUG", "/MD"])
elif platform == "javascript":
    env["ARCHITECTURE"] = "wasm"
    env["ENV"] = os.environ
    env["CC"] = "emcc"
    env["CXX"] = "em++"
    env["AR"] = "emar"
    env["RANLIB"] = "emranlib"
    env.Append(CPPFLAGS=["-s", "SIDE_MODULE=1","-s","ASSERTIONS=1"])
    env.Append(LINKFLAGS=["-s", "SIDE_MODULE=1","-s","ASSERTIONS=1"])
    env["SHOBJSUFFIX"] = ".bc"
    env["SHLIBSUFFIX"] = ".wasm"
    # Use TempFileMunge since some AR invocations are too long for cmd.exe.
    # Use POSIX-style paths, required with TempFileMunge.
    env["ARCOM_POSIX"] = env["ARCOM"].replace("$TARGET", "$TARGET.posix").replace("$SOURCES", "$SOURCES.posix")
    env["ARCOM"] = "${TEMPFILE(ARCOM_POSIX)}"

    # All intermediate files are just LLVM bitcode.
    env["OBJPREFIX"] = ""
    env["OBJSUFFIX"] = ".bc"
    env["PROGPREFIX"] = ""
    # Program() output consists of multiple files, so specify suffixes manually at builder.
    env["PROGSUFFIX"] = ""
    env["LIBPREFIX"] = "lib"
    env["LIBSUFFIX"] = ".bc"
    env["LIBPREFIXES"] = ["$LIBPREFIX"]
    env["LIBSUFFIXES"] = ["$LIBSUFFIX"]
    env.Replace(SHLINKFLAGS='$LINKFLAGS')
    env.Replace(SHLINKFLAGS='$LINKFLAGS')

def add_sources(sources, dir):
    for f in os.listdir(dir):
        if f.endswith(".cpp"):
            sources.append(dir + "/" + f)


env.Append(
    CPPPATH=[
        godot_headers_path,
        godot_bindings_path + "/include",
        godot_bindings_path + "/include/gen/",
        godot_bindings_path + "/include/core/",
    ]
)


#env.Append(LIBS=[env.File(os.path.join(godot_bindings_path, "bin", "libgodot-cpp.%s.%s.64%s" % (platform, target, env["LIBSUFFIX"])))])
env.Append(LIBS=[env.File(os.path.join(godot_bindings_path, "bin", "libgodot-cpp.%s.%s.%s%s" % (platform, target, env["ARCHITECTURE"],".a")))])

env.Append(LIBPATH=[os.path.join(godot_bindings_path, "bin")])

sources = []
add_sources(sources, "src")
add_sources(sources, "src/gamedata")
add_sources(sources, "src/buildings")
add_sources(sources, "src/ai")
add_sources(sources, "src/ai/actions")

#library = env.SharedLibrary(target="bin/libsimple", source=sources)
library = env.SharedLibrary(target=env['target_path'] + env['target_name'] , source=sources)

Default(library)


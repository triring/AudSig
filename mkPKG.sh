mkdir pkg_work/
mkdir pkg_work/AudSig
mkdir pkg_work/AudSig/examples
cp    AudSig.cpp         pkg_work/AudSig
cp    AudSig.h           pkg_work/AudSig
cp    github.css         pkg_work/AudSig
cp    keywords.txt       pkg_work/AudSig
cp    library.properties pkg_work/AudSig
cp    license.txt        pkg_work/AudSig
cp    readme.md          pkg_work/AudSig
cp -r examples           pkg_work/AudSig
cd pkg_work
## zip AudSig_1.0.2 AudSig/*.* AudSig/examples/*
zip -r AudSig_1.0.2.zip AudSig/
cp AudSig_1.0.2.zip ../dist
rm AudSig_1.0.2.zip
cd ..

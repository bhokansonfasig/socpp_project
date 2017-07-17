BINDIR = build

all: $(BINDIR)/test_ids $(BINDIR)/test_vectors $(BINDIR)/test_properties $(BINDIR)/test_particles

$(BINDIR)/test_ids : test_ids.cpp uniqueid.cpp
	clang++ -std=c++14 -stdlib=libc++ $^ -o $@

$(BINDIR)/test_vectors : test_vectors.cpp vector.cpp
	clang++ -std=c++14 -stdlib=libc++ $^ -o $@

$(BINDIR)/test_properties : test_properties.cpp properties.cpp sm_particles.cpp nuc_particles.cpp
	clang++ -std=c++14 -stdlib=libc++ $^ -o $@

$(BINDIR)/test_particles : test_particles.cpp particle.cpp properties.cpp sm_particles.cpp nuc_particles.cpp vector.cpp uniqueid.cpp
	clang++ -std=c++14 -stdlib=libc++ $^ -o $@

# may need to add -Weverything flag or similar at some point

clean:
	rm $(BINDIR)/*
{ stdenv
, cmake
, freeglut
, libGLU
}:
stdenv.mkDerivation {
  name = "PA2-bin";
  src = ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ freeglut libGLU ];
}

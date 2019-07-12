var assert = require("assert");
var tiffh = require("bindings")({
  module_root: __dirname,
  bindings: "tiffh"
});
var tiffhJS = require("../lib/tiffh");

// need to create test cases that verify the sizes and offsets of structs
// from native tiff.h vs tiffh.js (ref-struct)

describe("Validate Type Definitions", function() {
  describe("Types", function() {
    describe("Sizes", function() {
      let types = Object.getOwnPropertyNames(tiffh.typedefs.types);
      let ignore = [];
      types.forEach(type => {
        if (ignore.includes(type)) {
          return;
        }
        it("#" + type, function() {
          assert.strictEqual(
            tiffhJS[type].size,
            tiffh.typedefs.types[type].size,
            "Expected sizes to be equal:"
          );
        });
      });
    });
  });
  describe("Structs", function() {
    describe("Sizes", function() {
      let structs = Object.getOwnPropertyNames(tiffh.typedefs.structs);
      structs.forEach(struct => {
        it("#" + struct, function() {
          assert.strictEqual(
            tiffhJS[struct].size,
            tiffh.typedefs.structs[struct].size,
            "Expected sizes to be equal:"
          );
        });
      });
    });
  });
});

{
  "targets": [
    {
      "target_name": "tiffh",
      "sources": [ "src/tiffh.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
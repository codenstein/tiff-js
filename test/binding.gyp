{
  'targets': [
    {
      'target_name': 'tiffh',
      'sources': [ 'tiffh.cc' ],
      'include_dirs': [
        '<!(node -e "require(\'nan\')")'
      ],
    }
  ]
}
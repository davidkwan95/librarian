type imageLinks = {thumbnail: string};

type volumeInfo = {
  authors: option(array(string)),
  imageLinks,
  title: string,
  publisher: option(string),
};

type volume = {
  id: string,
  info: volumeInfo,
};

type volumes = list(volume);

module Decode = {
  let decodeImageLinks = json => {
    Json.Decode.{thumbnail: json |> field("thumbnail", string)};
  };

  let decodeVolumeInfo = json => {
    Json.Decode.{
      authors: json |> optional(field("authors", array(string))),
      imageLinks: json |> field("imageLinks", decodeImageLinks),
      title: json |> field("title", string),
      publisher: json |> optional(field("publisher", string)),
    };
  };

  let decodeVolume = json => {
    Json.Decode.{
      id: json |> field("id", string),
      info: json |> field("volumeInfo", decodeVolumeInfo),
    };
  };

  let decodeVolumes = json => {
    Json.Decode.(json |> field("items", list(decodeVolume)));
  };
};

module Api = {
  let fetchData = query => {
    Js.Promise.(
      Fetch.fetch(
        "https://www.googleapis.com/books/v1/volumes?key=AIzaSyCM7gQbGPgfTbCZHubXncrVi1MRcPkN37M&q="
        ++ query,
      )
      |> then_(Fetch.Response.json)
      |> then_(json => Decode.decodeVolumes(json) |> resolve)
    );
  };
};
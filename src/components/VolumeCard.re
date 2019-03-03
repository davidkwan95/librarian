let component = ReasonReact.statelessComponent("VolumeCard");

let make = (~volume: VolumeModules.volume, _children) => {
  ...component,
  render: _self => {
    let authors = volume.info.authors;
    let publisher = volume.info.publisher;
    let volumeUrl = "https://books.google.co.id/books?id=" ++volume.id
    let authorsNode = switch(authors) {
      | None => ReasonReact.null
      | Some(authors) => <div>{ReasonReact.string("By " ++Js.Array.joinWith(", ", authors))}</div>
    };
    let publisherNode = switch(publisher) {
      | None => ReasonReact.null
      | Some(publisher) => <div>{ReasonReact.string("Published by " ++publisher)}</div>
    };

    <a href=volumeUrl
      style=(ReactDOMRe.Style.make(
        ~textDecoration="none",
        ~color="inherit",
        ()
      ))
    >
      <div>
        <img
          src=volume.info.imageLinks.thumbnail
        />
      </div>
      <div>
        {ReasonReact.string(volume.info.title)}
        {authorsNode}
        {publisherNode}
      </div>
    </a>
  }
}



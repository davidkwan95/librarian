module Styles = {
  open Css;
  let card = style([width(px(480))]);

  let cardImage = style([width(px(128)), height(px(180))]);
};

let component = ReasonReact.statelessComponent("VolumeCard");

let make = (~volume: VolumeModules.volume, _children) => {
  ...component,
  render: _self => {
    let authors = volume.info.authors;
    let publisher = volume.info.publisher;
    let volumeUrl = "https://books.google.co.id/books?id=" ++ volume.id;
    let authorsNode =
      switch (authors) {
      | None => ReasonReact.null
      | Some(authors) =>
        <div>
          {ReasonReact.string("By " ++ Js.Array.joinWith(", ", authors))}
        </div>
      };
    let publisherNode =
      switch (publisher) {
      | None => ReasonReact.null
      | Some(publisher) =>
        <div> {ReasonReact.string("Published by " ++ publisher)} </div>
      };
    let imageLink =
      Js.String.replace(
        "http://",
        "https://",
        volume.info.imageLinks.thumbnail,
      );

    <div className={"card m-3 " ++ Styles.card}>
      <a
        href=volumeUrl
        style={ReactDOMRe.Style.make(
          ~textDecoration="none",
          ~color="inherit",
          (),
        )}>
        <div className="row no-gutters">
          <div className="col-md-4">
            <img src=imageLink className={"card-img " ++ Styles.cardImage} />
          </div>
          <div className="col-md-8">
            <div className="card-body">
              <h5> {ReasonReact.string(volume.info.title)} </h5>
              <small className="text-muted"> authorsNode </small>
              <small className="text-muted"> publisherNode </small>
            </div>
          </div>
        </div>
      </a>
    </div>;
  },
};
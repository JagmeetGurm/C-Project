using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;
namespace UsedGadgetsSale.Models
{
    public class GadgetDatabaseInitializer
   : DropCreateDatabaseIfModelChanges<GadgetContext>
    {
        protected override void Seed(GadgetContext context)
        {
            GetCategories().ForEach(c => context.Categories.Add(c));
            GetGadgets().ForEach(p => context.Gadgets.Add(p));
        }

        private static List<Category> GetCategories()
        {
            var categories = new List<Category> {
                new Category
                {
                    CategoryID = 1,
                    CategoryName = "CellPhones"
                },
                new Category
                {
                    CategoryID = 2,
                    CategoryName = "TV"
                },
                new Category
                {
                    CategoryID = 3,
                    CategoryName = "Laptops"
                },
                new Category
                {
                    CategoryID = 4,
                    CategoryName = "Cameras"
                },
                
            };

            return categories;
        }

        private static List<Gadget> GetGadgets()
        {
            var gadgets = new List<Gadget> {
                new Gadget
                {
                    GadgetID = 1,
                    GadgetName = "Flip Phone",
                    Description = "It's a flip phone which opens upon flipping." +
                                  "Power it up and let it go!",
                    ImagePath="carconvert.png",
                    UnitPrice = 22.50,
                    CategoryID = 1
               },
                new Gadget
                {
                    GadgetID = 2,
                    GadgetName = "Touch-screen phone",
                    Description = "use the phone by touching the screen with your fingers.",
                    ImagePath="carearly.png",
                    UnitPrice = 15.95,
                     CategoryID = 1
               },
                new Gadget
                {
                    GadgetID = 3,
                    GadgetName = "Nixon Camera",
                    Description = "12 Mpx nixon camera with recorder.",
                    ImagePath="carfast.png",
                    UnitPrice = 32.99,
                    CategoryID = 1
                },
                new Gadget
                {
                    GadgetID = 4,
                    GadgetName = "Sony Camera",
                    Description = "Sony's 14 Mpx camera with image stablizer",
                    ImagePath="carfaster.png",
                    UnitPrice = 8.95,
                    CategoryID = 1
                },
                new Gadget
                {
                    GadgetID = 5,
                    GadgetName="Samsung TV",
                    Description = "50 inch color television.",
                    ImagePath="carracer.png",
                    UnitPrice = 34.95,
                    CategoryID = 1
                },
                new Gadget
                {
                    GadgetID = 6,
                    GadgetName = "LG TV",
                    Description = "30 inch color TV.",
                    ImagePath="planeace.png",
                    UnitPrice = 95.00,
                    CategoryID = 2
                },
                new Gadget
                {
                    GadgetID = 7,
                    GadgetName = "Acer Laptop",
                    Description = "Acer's 15 inch laptop.",
                    ImagePath="planeglider.png",
                    UnitPrice = 4.95,
                    CategoryID = 2
                },
                new Gadget
                {
                    GadgetID = 8,
                    GadgetName = "Asus Laptop",
                    Description = "11 inch Asus Tiachi dual-screen laptop.",
                    ImagePath="planepaper.png",
                    UnitPrice = 2.95,
                    CategoryID = 2
                }
                
            };

            return gadgets;
        }
    }
}